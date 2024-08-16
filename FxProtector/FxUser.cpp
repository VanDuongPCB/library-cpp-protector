#include "FxUser.h"


FxUser::FxUser()
{

}

FxUser::FxUser( const QString& id, const QString& pass ) :
m_id(id),
m_name(id),
m_password(pass)
{

}

FxUser::~FxUser()
{

}

const QString FxUser::GetName() const
{
    return m_name;
}