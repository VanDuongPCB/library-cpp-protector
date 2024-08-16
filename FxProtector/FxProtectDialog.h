#pragma once
#include "FxProtectorAPI.h"
#include "FxDialog.h"


namespace Ui
{
    class ProtectDialog;
}

class FX_PROTECTOR_API FxProtectDialog : public FxDialog
{
    Q_OBJECT
public:
    explicit FxProtectDialog( QWidget* parent = nullptr );
    ~FxProtectDialog();

private slots:
    void OnLogin();

private:
    Ui::ProtectDialog* ui;
};

