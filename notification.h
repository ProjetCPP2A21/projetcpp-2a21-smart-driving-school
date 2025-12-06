#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLinearGradient>
#include <QPainterPath>
#include <QDateTime>
#include "module.h"

enum class NotificationType {
    THEORY,     // Module théorique
    PRACTICE,   // Module pratique
    REMINDER,   // Rappel de cours
    TIP,        // Conseil pédagogique
    ALERT,      // Alerte administrative
    MOTIVATION, // Message de motivation
    INFORMATION // Information générale
};

class Notification : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)

public:
    static const int WIDTH = 320;
    static const int HEIGHT = 100;

    explicit Notification(QWidget *parent = nullptr);
    ~Notification();

    // Propriété pour l'animation de survol
    Q_PROPERTY(qreal hoverProgress READ hoverProgress WRITE setHoverProgress)

    qreal hoverProgress() const { return m_hoverProgress; }
    void setHoverProgress(qreal progress);

    enum class Position {
        TopRight,
        BottomRight,
        TopLeft,
        BottomLeft,
        Center
    };

    void setPosition(Position position);
    void moveAnimated(const QPoint &pos);

    void showNotification(const QString &title, const QString &message,
                          NotificationType type = NotificationType::INFORMATION,
                          int moduleId = -1, int displayTime = 5000);

    qreal opacity() const;
    void setOpacity(qreal opacity);

    // Obtenir les informations du module
    int getModuleId() const { return m_moduleId; }
    QString getModuleName() const { return m_moduleName; }

signals:
    void notificationClicked(NotificationType type, const QString &title, int moduleId = -1);
    void closed(Notification* notif);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void hideNotification();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void setupUI();
    void setupAnimations();
    void updateHoverStyle();
    void updateStyleSheet();
    QColor getColorForType(NotificationType type) const;
    QColor getDarkerColor(const QColor &color, int factor = 120) const;
    QString getIconForType(NotificationType type) const;
    QColor getTextColor() const;
    bool isDarkTheme() const;

    // Animation
    void setupShowAnimation();
    void setupHideAnimation();
    void setupMoveAnimation();

    // UI Elements
    QLabel *m_titleLabel;
    QLabel *m_messageLabel;
    QLabel *m_iconLabel;
    QPushButton *m_closeButton;

    // Animation et effets
    QTimer *m_timer;
    QPropertyAnimation *m_animation;
    QPropertyAnimation *m_hoverAnimation;
    QPropertyAnimation *m_showAnimation;
    QPropertyAnimation *m_hideAnimation;
    QGraphicsOpacityEffect *m_opacityEffect;
    QGraphicsDropShadowEffect *m_shadowEffect;

    // Data
    QString m_title;
    QString m_message;
    NotificationType m_type;
    int m_moduleId;
    QString m_moduleName;
    qreal m_opacity;
    qreal m_hoverProgress = 0.0;
    bool m_isHovered = false;
    Position m_position;
    QDateTime m_creationTime;
    bool m_hovered = false;
};

#endif // NOTIFICATION_H
