///////////////////////////////////////////////////////////////////////////////
//
// mSIGNA
//
// networksettingsdialog.h
//
// Copyright (c) 2013 Eric Lombrozo
// Copyright (c) 2011-2016 Ciphrex Corp.
//
// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
//

#if defined(HAVE_CONFIG_H)
#include "config/msigna-config.h"
#endif

#pragma once

class QLineEdit;
class QCheckBox;

#include <QDialog>

class NetworkSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    NetworkSettingsDialog(const QString& host, int port, bool autoConnect, QWidget* parent = NULL);

    QString getHost() const;
    int getPort() const;
    bool getAutoConnect() const;

private:
    QLineEdit* hostEdit;
    QLineEdit* portEdit;
    QCheckBox* autoConnectCheckBox;
};

