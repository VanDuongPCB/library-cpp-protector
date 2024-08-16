#include "FxProtectDialog.h"
#include "ui_ProtectDialog.h"

#include "FxProtectorServices.h"

FxProtectDialog::FxProtectDialog( QWidget* parent ) : FxDialog( parent ), ui(new Ui::ProtectDialog )
{
    ui->setupUi( this );
    connect( ui->btnLogin, &QPushButton::clicked, this, &FxProtectDialog::OnLogin );
}

FxProtectDialog::~FxProtectDialog()
{
}

void FxProtectDialog::OnLogin()
{
    if ( GetProtectorServices()->Login( ui->txtUserName->text(), ui->txtPassword->text() ) )
    {
        this->close();
    }
}