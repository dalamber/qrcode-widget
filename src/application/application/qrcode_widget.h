#pragma once

#include <QWidget>

namespace qrcode {

class QRCodeWidget : public QWidget {
    Q_OBJECT

public:
    explicit QRCodeWidget(QWidget *parent = nullptr);
    void updateQRCode(QString text);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void generateImageFromText();
    QImage _qrCodeImage;
    QString _text;
};

}
