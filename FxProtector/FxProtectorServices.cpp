#include "FxProtectorServices.h"
#include "FxRounedButton.h"
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
    m_User = FxUser();
    emit LoginChanged( m_User );
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

    button->setText( "User");
    return m_controlWidget;
}
//
//void FxThemeServices::OnNextTheme()
//{
//    QMap<int, FxTheme> themes = Availableds();
//    if ( themes.size() < 1 )
//        return;
//
//    for ( auto it = themes.begin(); it != themes.end(); it++ )
//    {
//        if ( it.value().GetName() == m_themeData.GetName() )
//        {
//            int nextIndex = it.key() + 1;
//            if ( !themes.contains( nextIndex ) )
//                nextIndex = 0;
//            SetTheme( themes[ nextIndex ].GetName() );
//            GetControlWidget();
//            break;
//        }
//    }
//}

FxProtectorServices* GetProtectorServices()
{
    static FxProtectorServices instance;
    return &instance;
}