#include "notification.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QTimer>
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QFontMetrics>
#include <QLinearGradient>
#include <QDateTime>
#include <QTime>
#include <QStyle>
#include <QStyleOption>

// Durées d'animation en millisecondes
const int ANIMATION_DURATION = 300;
const int NOTIFICATION_TIMEOUT = 5000; // 5 secondes par défaut

Notification::Notification(QWidget *parent)
    : QWidget(parent)
    , m_opacity(1.0)
    , m_moduleId(-1)
    , m_timer(new QTimer(this))
    , m_animation(nullptr)
    , m_hoverAnimation(new QPropertyAnimation(this, "hoverProgress", this))
    , m_showAnimation(new QPropertyAnimation(this, "opacity", this))
    , m_hideAnimation(new QPropertyAnimation(this, "opacity", this))
    , m_opacityEffect(new QGraphicsOpacityEffect(this))
    , m_shadowEffect(new QGraphicsDropShadowEffect(this))
    , m_titleLabel(new QLabel(this))
    , m_messageLabel(new QLabel(this))
    , m_iconLabel(new QLabel(this))
    , m_closeButton(new QPushButton(this))
{
    // Configuration de la fenêtre
    setWindowFlags(Qt::FramelessWindowHint | 
                  Qt::Tool | 
                  Qt::WindowStaysOnTopHint | 
                  Qt::WindowDoesNotAcceptFocus);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
    setWindowOpacity(0);
    
    // Configuration de l'ombre
    m_shadowEffect->setBlurRadius(20);
    m_shadowEffect->setColor(QColor(0, 0, 0, 100));
    m_shadowEffect->setOffset(0, 4);
    setGraphicsEffect(m_shadowEffect);
    
    // Configuration des animations
    setupAnimations();
    
    // Configuration du minuteur
    m_timer->setSingleShot(true);
    connect(m_timer, &QTimer::timeout, this, &Notification::hideNotification);
    
    // Configuration de l'interface utilisateur
    setupUI();
    
    // Style par défaut
    updateStyleSheet();
}

Notification::~Notification()
{
    // Stop all animations first
    if (m_animation && m_animation->state() == QPropertyAnimation::Running) {
        m_animation->stop();
    }
    if (m_hoverAnimation && m_hoverAnimation->state() == QPropertyAnimation::Running) {
        m_hoverAnimation->stop();
    }
    if (m_showAnimation && m_showAnimation->state() == QPropertyAnimation::Running) {
        m_showAnimation->stop();
    }
    if (m_hideAnimation && m_hideAnimation->state() == QPropertyAnimation::Running) {
        m_hideAnimation->stop();
    }
    
    // Stop and delete timer
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
    
    // Delete animations
    delete m_animation;
    delete m_hoverAnimation;
    delete m_showAnimation;
    delete m_hideAnimation;
    
    // Delete effects
    delete m_opacityEffect;
    delete m_shadowEffect;
}

void Notification::showNotification(const QString &title, const QString &message, 
                                  NotificationType type, int moduleId, int displayTime)
{
    // Mise à jour des données
    m_title = title;
    m_message = message;
    m_type = type;
    m_moduleId = moduleId;
    
    // Mise à jour de l'interface utilisateur
    QString icon = getIconForType(type);
    m_titleLabel->setText(QString("%1 %2").arg(icon, m_title));
    m_messageLabel->setText(m_message);
    
    // Créer un QPixmap avec l'icône
    QPixmap pixmap(32, 32);
    pixmap.fill(Qt::transparent);
    
    QPainter painter(&pixmap);
    QFont font = painter.font();
    font.setPointSize(20); // Taille de police plus grande pour l'icône
    painter.setFont(font);
    painter.drawText(pixmap.rect(), Qt::AlignCenter, icon);
    
    m_iconLabel->setPixmap(pixmap);
    
    // Mise à jour du style en fonction du type
    updateStyleSheet();
    
    // Ajustement de la taille
    adjustSize();
    
    // Positionnement en bas à droite de l'écran avec un léger décalage
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = screenGeometry.width() - width() - 20;
    int y = screenGeometry.height() - height() - 20;
    
    // TODO: Implémenter la gestion des piles de notifications
    
    // Définir la position
    move(x, y);
    
    // Démarrer le minuteur de disparition
    m_timer->stop();
    if (displayTime > 0) {
        m_timer->start(displayTime);
    } else {
        m_timer->start(NOTIFICATION_TIMEOUT);
    }
    
    // Afficher et démarrer l'animation d'apparition
    show();
    raise();
    activateWindow();
    m_showAnimation->start();
}

qreal Notification::opacity() const
{
    return m_opacity;
}

void Notification::setOpacity(qreal opacity)
{
    if (qFuzzyCompare(m_opacity, opacity))
        return;

    m_opacity = opacity;
    setWindowOpacity(opacity);
    
    // Mettre à jour l'opacité de l'ombre en fonction de l'opacité de la fenêtre
    QColor shadowColor = m_shadowEffect->color();
    shadowColor.setAlpha(static_cast<int>(opacity * 100));
    m_shadowEffect->setColor(shadowColor);
    
    update();
}

void Notification::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Créer un chemin arrondi pour le fond
    QPainterPath path;
    path.addRoundedRect(rect(), 8, 8);
    
    // Remplir avec un dégradé
    QLinearGradient gradient(0, 0, 0, height());
    QColor baseColor = getColorForType(m_type);
    gradient.setColorAt(0, baseColor.lighter(110));
    gradient.setColorAt(1, baseColor);
    
    painter.fillPath(path, gradient);
    
    // Dessiner une bordure subtile
    painter.setPen(QPen(QColor(255, 255, 255, 30), 1));
    painter.drawPath(path);
}

void Notification::mousePressEvent(QMouseEvent *event)
{
    if (event && event->button() == Qt::LeftButton) {
        emit notificationClicked(m_type, m_title, m_moduleId);
        hideNotification();
    }
    QWidget::mousePressEvent(event);
}

void Notification::hideNotification()
{
    // Arrêt du minuteur
    m_timer->stop();
    
    // Arrêter l'animation en cours
    if (m_showAnimation->state() == QPropertyAnimation::Running) {
        m_showAnimation->stop();
    }
    
    // Démarrer l'animation de disparition
    m_hideAnimation->start();
}

void Notification::setupUI()
{
    // Configuration des labels
    m_titleLabel->setWordWrap(true);
    m_titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_titleLabel->setStyleSheet("font-weight: bold; color: white; font-size: 12px;");
    
    m_messageLabel->setWordWrap(true);
    m_messageLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_messageLabel->setStyleSheet("color: rgba(255, 255, 255, 0.9); font-size: 11px;");
    
    // Configuration du bouton de fermeture
    m_closeButton->setFixedSize(16, 16);
    m_closeButton->setStyleSheet(
        "QPushButton {\n"
        "    border: none;\n"
        "    color: white;\n"
        "    font-weight: bold;\n"
        "    border-radius: 8px;\n"
        "    background-color: rgba(255, 255, 255, 0.2);\n"
        "}\n"
        "QPushButton:hover {\n"
        "    background-color: rgba(255, 255, 255, 0.3);\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: rgba(255, 255, 255, 0.4);\n"
        "}"
    );
    m_closeButton->setText("×");
    
    connect(m_closeButton, &QPushButton::clicked, this, &Notification::hideNotification);
    
    // Configuration du layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QHBoxLayout *contentLayout = new QHBoxLayout();
    
    // Configuration de l'icône
    m_iconLabel->setFixedSize(32, 32);
    m_iconLabel->setAlignment(Qt::AlignCenter);
    
    // Configuration des marges et espacements
    setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(8);
    headerLayout->setSpacing(8);
    contentLayout->setSpacing(12);
    
    // Construction du layout
    headerLayout->addWidget(m_iconLabel);
    headerLayout->addWidget(m_titleLabel, 1);
    headerLayout->addWidget(m_closeButton);
    
    contentLayout->addSpacing(40); // Alignement avec le titre
    contentLayout->addWidget(m_messageLabel, 1);
    
    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(contentLayout);
    
    setLayout(mainLayout);
    setFixedSize(320, 120); // Taille par défaut, s'ajustera au contenu
}

void Notification::setupAnimations()
{
    // Animation d'apparition
    m_showAnimation->setDuration(ANIMATION_DURATION);
    m_showAnimation->setStartValue(0.0);
    m_showAnimation->setEndValue(1.0);
    m_showAnimation->setEasingCurve(QEasingCurve::OutBack);
    
    // Animation de disparition
    m_hideAnimation->setDuration(ANIMATION_DURATION);
    m_hideAnimation->setStartValue(1.0);
    m_hideAnimation->setEndValue(0.0);
    m_hideAnimation->setEasingCurve(QEasingCurve::InBack);
    
    // Connecter la fin de l'animation de disparition à la fermeture
    connect(m_hideAnimation, &QPropertyAnimation::finished, this, &Notification::close);
}

void Notification::updateStyleSheet()
{
    QColor bgColor = getColorForType(m_type);
    QColor borderColor = bgColor.darker(120);
    
    // Création d'un dégradé pour le fond
    QString gradient = QString("qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                             "stop:0 %1, stop:0.8 %2)")
                      .arg(bgColor.lighter(110).name())
                      .arg(bgColor.darker(110).name());
    
    // Choisir la couleur du texte en fonction de la luminosité de la couleur de fond
    bool isLightColor = (bgColor.red() * 0.299 + bgColor.green() * 0.587 + bgColor.blue() * 0.114) > 180;
    QString textColor = isLightColor ? "#333333" : "#FFFFFF";
    
    // Construire la feuille de style en plusieurs parties
    QString titleStyle = QString(
        "QLabel#title { "
        "  color: %1; "
        "  font-weight: 600; "
        "  font-size: 13px; "
        "  padding: 0; "
        "  margin: 0; "
        "  border: none; "
        "  font-family: 'Segoe UI', Arial, sans-serif; "
        "}"
    ).arg(textColor);
    
    QString messageStyle = QString(
        "QLabel#message { "
        "  color: %1; "
        "  font-size: 12px; "
        "  padding: 0; "
        "  margin: 4px 0 0 0; "
        "  border: none; "
        "  line-height: 1.3; "
        "  font-family: 'Segoe UI', Arial, sans-serif; "
        "  opacity: 0.9; "
        "}"
    ).arg(textColor);
    
    QString buttonStyle = 
        "QPushButton { "
        "  background: rgba(255, 255, 255, 0.15); "
        "  border: 1px solid rgba(255, 255, 255, 0.2); "
        "  color: white; "
        "  font-weight: 500; "
        "  font-size: 13px; "
        "  padding: 2px 8px; "
        "  border-radius: 4px; "
        "  min-width: 24px; "
        "  min-height: 24px; "
        "  font-family: 'Segoe UI', Arial, sans-serif; "
        "}"
        "QPushButton:hover { "
        "  background: rgba(255, 255, 255, 0.25); "
        "  border-color: rgba(255, 255, 255, 0.3); "
        "}"
        "QPushButton:pressed { "
        "  background: rgba(255, 255, 255, 0.35); "
        "}";
    
    // Combiner tous les styles
    QString styleSheet = titleStyle + messageStyle + buttonStyle;
    
    // Appliquer le style avec le dégradé
    setStyleSheet(QString("Notification { "
                         "background: %1; "
                         "border: 1px solid %2; "
                         "border-radius: 8px; "
                         "}"
                         "%3")
                 .arg(gradient)
                 .arg(borderColor.name())
                 .arg(styleSheet));
}

void Notification::updateHoverStyle()
{
    QColor baseColor = getColorForType(m_type);
    QColor hoverColor = baseColor.darker(120);
    
    // Style pour le titre
    QString titleStyle = QString(
        "font-weight: bold; "
        "color: %1; "
        "font-size: 12px;"
    ).arg(hoverColor.name());
    
    // Style pour le message
    QString messageStyle = QString(
        "color: %1; "
        "font-size: 11px;"
    ).arg(hoverColor.lighter(150).name());
    
    m_titleLabel->setStyleSheet(titleStyle);
    m_messageLabel->setStyleSheet(messageStyle);
    
    // Mise à jour de l'icône
    m_iconLabel->setPixmap(QPixmap(getIconForType(m_type)).scaled(24, 24, 
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
    
    // Mise à jour du style
    QWidget::update();
}

void Notification::setHoverProgress(qreal progress)
{
    if (qFuzzyCompare(m_hoverProgress, progress))
        return;

    m_hoverProgress = progress;
    updateHoverStyle();
}

void Notification::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    m_isHovered = true;
    
    // Arrêter le minuteur de fermeture automatique
    if (m_timer->isActive()) {
        m_timer->stop();
    }
    
    // Démarrer l'animation de survol
    if (m_hoverAnimation) {
        m_hoverAnimation->stop();
        m_hoverAnimation->setStartValue(m_hoverProgress);
        m_hoverAnimation->setEndValue(1.0);
        m_hoverAnimation->setDuration(150);
        m_hoverAnimation->start();
    }
}

void Notification::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_isHovered = false;
    
    // Redémarrer le minuteur de fermeture automatique
    if (!m_timer->isActive()) {
        m_timer->start();
    }
    
    // Démarrer l'animation de sortie du survol
    if (m_hoverAnimation) {
        m_hoverAnimation->stop();
        m_hoverAnimation->setStartValue(m_hoverProgress);
        m_hoverAnimation->setEndValue(0.0);
        m_hoverAnimation->setDuration(150);
        m_hoverAnimation->start();
    }
}

QColor Notification::getColorForType(NotificationType type) const
{
    switch (type) {
        case NotificationType::THEORY:
            return QColor(41, 128, 185);    // Bleu
        case NotificationType::PRACTICE:
            return QColor(39, 174, 96);     // Vert
        case NotificationType::REMINDER:
            return QColor(155, 89, 182);    // Violet
        case NotificationType::TIP:
            return QColor(22, 160, 133);    // Turquoise
        case NotificationType::ALERT:
            return QColor(231, 76, 60);     // Rouge
        case NotificationType::MOTIVATION:
            return QColor(255, 193, 7);     // Jaune plus clair et plus vif
        default:
            return QColor(52, 152, 219);    // Bleu par défaut
    }
}

QString Notification::getIconForType(NotificationType type) const
{
    // Retourne uniquement l'emoji correspondant au type de notification
    switch (type) {
        case NotificationType::THEORY:     return "📚";  // Livres pour la théorie
        case NotificationType::PRACTICE:   return "🚗";  // Voiture pour la pratique
        case NotificationType::REMINDER:   return "⏰";  // Réveil pour les rappels
        case NotificationType::TIP:        return "💡";  // Ampoule pour les conseils
        case NotificationType::ALERT:      return "⚠️";  // Attention pour les alertes
        case NotificationType::MOTIVATION: return "💪";  // Biceps pour la motivation
        case NotificationType::INFORMATION:return "ℹ️";  // Info pour les messages généraux
        default:                           return "✨";  // Étincelles par défaut
    }
}
