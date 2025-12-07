#ifndef QRCODE_H
#define QRCODE_H

#include <vector>
#include <string>

/*
 * A simple QR code generator class
 */
class QrCode {
public:
    enum class Ecc {
        LOW = 0,
        MEDIUM,
        QUARTILE,
        HIGH,
    };

    // Constructeur pour encoder du texte
    static QrCode encodeText(const char *text, Ecc ecl);
    
    // Constructeur pour encoder des données binaires
    static QrCode encodeBinary(const std::vector<std::uint8_t> &data, Ecc ecl);
    
    // Accesseurs
    int getSize() const { return size; }
    bool getModule(int x, int y) const;

private:
    // Constructeur privé
    QrCode(int ver, Ecc ecl, const std::vector<std::uint8_t> &dataCodewords);
    
    // Méthodes de construction du QR code
    void drawFunctionPatterns();
    void drawFormatBits(int mask);
    void drawVersion();
    void drawFinderPattern(int x, int y);
    void drawAlignmentPattern(int x, int y);
    void setupPositionProbePattern(int row, int col);
    
    // Constantes
    static const int PENALTY_N1 = 3;
    static const int PENALTY_N2 = 3;
    static const int PENALTY_N3 = 40;
    static const int PENALTY_N4 = 10;
    
    // Champs
    int version;          // Version du QR code (1-40 pour QR Code 2005)
    int size;             // Taille du QR code en modules (21 + 4*(version-1))
    Ecc errorCorrectionLevel;
    std::vector<std::vector<bool>> modules;  // Les modules du QR code
    std::vector<std::vector<bool>> isFunction; // Marque les modules de fonction
};

#endif // QRCODE_H
