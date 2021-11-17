/********************************************************************************
** Form generated from reading UI file 'xdisk_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XDISK_GUI_H
#define UI_XDISK_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XDiskGUIClass
{
public:
    QPushButton *refleshButton;
    QPushButton *uploadButton;
    QTableWidget *filelistWidget;
    QLineEdit *ipEdit;
    QSpinBox *portBox;
    QLineEdit *pathEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *downloadButton;

    void setupUi(QWidget *XDiskGUIClass)
    {
        if (XDiskGUIClass->objectName().isEmpty())
            XDiskGUIClass->setObjectName(QString::fromUtf8("XDiskGUIClass"));
        XDiskGUIClass->resize(612, 433);
        refleshButton = new QPushButton(XDiskGUIClass);
        refleshButton->setObjectName(QString::fromUtf8("refleshButton"));
        refleshButton->setGeometry(QRect(490, 170, 81, 41));
        uploadButton = new QPushButton(XDiskGUIClass);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        uploadButton->setGeometry(QRect(490, 220, 81, 41));
        filelistWidget = new QTableWidget(XDiskGUIClass);
        if (filelistWidget->columnCount() < 2)
            filelistWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        filelistWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        filelistWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        filelistWidget->setObjectName(QString::fromUtf8("filelistWidget"));
        filelistWidget->setGeometry(QRect(0, 0, 481, 431));
        filelistWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        ipEdit = new QLineEdit(XDiskGUIClass);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setGeometry(QRect(490, 80, 113, 20));
        portBox = new QSpinBox(XDiskGUIClass);
        portBox->setObjectName(QString::fromUtf8("portBox"));
        portBox->setGeometry(QRect(490, 130, 111, 21));
        portBox->setMaximum(65535);
        portBox->setValue(21002);
        pathEdit = new QLineEdit(XDiskGUIClass);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(490, 30, 113, 20));
        label = new QLabel(XDiskGUIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(490, 10, 111, 16));
        label_2 = new QLabel(XDiskGUIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 60, 111, 16));
        label_3 = new QLabel(XDiskGUIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 110, 111, 16));
        downloadButton = new QPushButton(XDiskGUIClass);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(490, 280, 81, 41));

        retranslateUi(XDiskGUIClass);
        QObject::connect(refleshButton, SIGNAL(clicked()), XDiskGUIClass, SLOT(Refresh()));
        QObject::connect(uploadButton, SIGNAL(clicked()), XDiskGUIClass, SLOT(Upload()));
        QObject::connect(downloadButton, SIGNAL(clicked()), XDiskGUIClass, SLOT(Download()));

        QMetaObject::connectSlotsByName(XDiskGUIClass);
    } // setupUi

    void retranslateUi(QWidget *XDiskGUIClass)
    {
        XDiskGUIClass->setWindowTitle(QCoreApplication::translate("XDiskGUIClass", "XDiskGUI", nullptr));
        refleshButton->setText(QCoreApplication::translate("XDiskGUIClass", "\345\210\267\346\226\260", nullptr));
        uploadButton->setText(QCoreApplication::translate("XDiskGUIClass", "\344\270\212\344\274\240", nullptr));
        QTableWidgetItem *___qtablewidgetitem = filelistWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("XDiskGUIClass", "\346\226\207\344\273\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = filelistWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("XDiskGUIClass", "\346\226\207\344\273\266\345\244\247\345\260\217", nullptr));
        ipEdit->setText(QCoreApplication::translate("XDiskGUIClass", "127.0.0.1", nullptr));
        pathEdit->setText(QCoreApplication::translate("XDiskGUIClass", "./server_root", nullptr));
        label->setText(QCoreApplication::translate("XDiskGUIClass", "\346\234\215\345\212\241\345\231\250\350\267\257\345\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("XDiskGUIClass", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        label_3->setText(QCoreApplication::translate("XDiskGUIClass", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        downloadButton->setText(QCoreApplication::translate("XDiskGUIClass", "\344\270\213\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XDiskGUIClass: public Ui_XDiskGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XDISK_GUI_H
