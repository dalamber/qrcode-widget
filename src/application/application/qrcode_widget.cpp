#include "qrcode_widget.h"

#include <QPainter>
#include <QResizeEvent>
#include <utility>
#include <qrencode.h>

namespace qrcode {

QRCodeWidget::QRCodeWidget(QWidget *parent)
    : QWidget(parent)
    , _qrCodeImage(QSize(200, 200)
    , QImage::Format_RGB32)
{
    setMinimumSize(200, 200);
}

void QRCodeWidget::updateQRCode(QString text)
{
    _text = text;
    generateImageFromText();
    update();
}

void QRCodeWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(rect(), _qrCodeImage);
}

void QRCodeWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);

    generateImageFromText();
    update();
}

void QRCodeWidget::generateImageFromText()
{
    _qrCodeImage = QImage(size(), QImage::Format_RGB32);

    QRcode *qrcode = QRcode_encodeString(_text.toStdString().c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode != nullptr) {
        QPainter painter(&_qrCodeImage);
        painter.setBrush(Qt::black);
        painter.setRenderHint(QPainter::Antialiasing);
        const int qrSize = qrcode->width > 0 ? qrcode->width : 1;
        const double scale = size().width() / static_cast<double>(qrSize);
        for (int y = 0; y < qrSize; ++y) {
            for (int x = 0; x < qrSize; ++x) {
                unsigned char value = qrcode->data[y * qrSize + x];
                if (value & 0x01) {
                    QRectF rect(x * scale, y * scale, scale, scale);
                    painter.fillRect(rect, Qt::black);
                }
            }
        }
        QRcode_free(qrcode);
    }
}

}
