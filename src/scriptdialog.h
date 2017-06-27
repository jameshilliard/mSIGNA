///////////////////////////////////////////////////////////////////////////////
//
// mSIGNA
//
// scriptdialog.h
//
// Copyright (c) 2013-2014 Eric Lombrozo
// Copyright (c) 2011-2016 Ciphrex Corp.
//
// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
//

#if defined(HAVE_CONFIG_H)
#include "config/msigna-config.h"
#endif

#pragma once

#include <CoinDB/Vault.h>

class ScriptModel;
class ScriptView;

#include <QDialog>

class ScriptDialog : public QDialog
{
    Q_OBJECT

public:
    ScriptDialog(CoinDB::Vault* vault, const QString& accountName, QWidget* parent = NULL);

private:
    ScriptModel* scriptModel;
    ScriptView* scriptView;
};

