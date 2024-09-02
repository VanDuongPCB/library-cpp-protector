#pragma once
#include "FxProtectorAPI.h"
#include "FxUser.h"

#include <QObject>

class FX_PROTECTOR_API FxProtectorServices : public QObject
{
    Q_OBJECT
public:
    FxProtectorServices( QObject* parent = nullptr );
    ~FxProtectorServices();
    void Logout();
    bool Login( const QString& id, const QString& password );
    bool IsLogin();
    const FxUser GetUser();
    bool CheckUser( const QString& id );
    bool AddUser( const QString& id );
    FxUser FindUser( const QString& id );
    const QList<FxUser> GetUsers();

    QWidget* GetControlWidget();
signals:
    void LoginChanged( const FxUser& user );

private slots:
    void OnLoginOrLogout();

private:
    FxUser m_User;
    QWidget* m_controlWidget;
};

FxProtectorServices FX_PROTECTOR_API* GetProtectorServices();