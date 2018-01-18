//////////////////////////////////////////////////////////////////////////
//
// pgAdmin 4 - PostgreSQL Tools
//
// Copyright (C) 2013 - 2018, The pgAdmin Development Team
// This software is released under the PostgreSQL Licence
//
// TrayIcon.h - Manages the tray icon
//
//////////////////////////////////////////////////////////////////////////

#ifndef TRAYICON_H
#define TRAYICON_H

#include "pgAdmin4.h"

// QT headers
#include <QWidget>
#include <QMessageBox>

class TrayIcon : public QWidget
{
    Q_OBJECT

public:
    TrayIcon();
    ~TrayIcon();

    bool Init();
    void setAppServerUrl(QString appServerUrl);

private:
    void createTrayIcon();
    bool isSystemTrayAvailable();
    void createActions();

    void wait(int msec);

    QAction *m_newAction;
    QAction *m_configAction;
    QAction *m_quitAction;

    QSystemTrayIcon *m_trayIcon;
    QMenu *m_trayIconMenu;

    QString m_appServerUrl;

private slots:
    void onNew();
    void onConfig();
    void onQuit();
};

#endif // TRAYICON_H
