#pragma once
#include "FxProtectorAPI.h"

#include <QString>
#include <QMap>
#include <QColor>
#include <QPalette>
#include <QIcon>

class FX_PROTECTOR_API FxUser
{
public:
	FxUser();
	FxUser( const QString& name, const QString& pass );
	~FxUser();
	const QString GetName() const;

private:
	QString m_id;
	QString m_password;
	QString m_name;
	QIcon m_Icon;
};