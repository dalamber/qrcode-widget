#include <QApplication>
#include <QMainWindow>

#include <QLineEdit>
#include <QVBoxLayout>

#include "qrcode_widget.h"

class SimpleContainer : public QWidget
{
    qrcode::QRCodeWidget *_qrcodeWidget = nullptr;
    QLineEdit *_lineEdit = nullptr;
public:
    explicit SimpleContainer(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        _qrcodeWidget = new qrcode::QRCodeWidget(this);
        _lineEdit = new QLineEdit(this);

        connect(_lineEdit, &QLineEdit::textEdited, _qrcodeWidget, &qrcode::QRCodeWidget::updateQRCode);

        auto mainLayout = new QVBoxLayout();
        mainLayout->addWidget(_lineEdit);
        mainLayout->addWidget(_qrcodeWidget);

        setLayout(mainLayout);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SimpleContainer container;
    container.show();

    return QApplication::exec();
}
