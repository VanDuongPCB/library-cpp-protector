#include "FxProtectorServices.h"
#include "FxRounedButton.h"
#include "FxMessageBox.h"
#include "FxProtectDialog.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>


FxProtectorServices::FxProtectorServices( QObject* parent ) : QObject( parent ),
m_controlWidget( nullptr )
{
    QString appPath = QCoreApplication::applicationDirPath();
    QString themeDir = appPath + "/themes";
    QDir().mkdir( themeDir );
}

FxProtectorServices::~FxProtectorServices()
{
}

void FxProtectorServices::Logout()
{
    if ( FxMessageBox( "Bạn có chắc chắn muốn đăng xuất không ?", "Khoan đã", FxMessageBox::Question, FxMessageBox::Yes | FxMessageBox::No ).exec() == FxMessageBox::Yes )
    {
        m_User = FxUser();
        emit LoginChanged( m_User );
    }
}

bool FxProtectorServices::Login( const QString& id, const QString& password )
{
    m_User = FxUser( id, password );
    emit LoginChanged( m_User );
    return true;
}

bool  FxProtectorServices::IsLogin()
{
    return !m_User.GetName().isEmpty();
}

const FxUser FxProtectorServices::GetUser()
{
    return m_User;
}

bool FxProtectorServices::CheckUser( const QString& id )
{
    return true;
}

bool FxProtectorServices::AddUser( const QString& id )
{
    return false;
}

FxUser FxProtectorServices::FindUser( const QString& id )
{
    return {};
}

const QList<FxUser> FxProtectorServices::GetUsers()
{
    return {};
}

void FxProtectorServices::OnLoginOrLogout()
{
    if ( IsLogin() )
    {
        Logout();
    }
    else
    {
        FxProtectDialog dialog;
        dialog.exec();
    }
}

QWidget* FxProtectorServices::GetControlWidget()
{
    FxRounedButton* button = static_cast< FxRounedButton* >( m_controlWidget );
    if ( !button )
    {
        button = new FxRounedButton();
        button->setFixedSize( QSize( 100, 25 ) );
        connect( button, &FxRounedButton::clicked, this, &FxProtectorServices::OnLoginOrLogout );
        m_controlWidget = button;
    }

    button->setText( "User" );
    return m_controlWidget;
}

FxProtectorServices* GetProtectorServices()
{
    static FxProtectorServices instance;
    return &instance;
}