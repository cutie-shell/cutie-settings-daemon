#ifndef OFONO_H
#define OFONO_H

#include <QDebug>
#include <iostream>

#include "structures.h"

#include "ofono_interface.h"
#include "ofono_modem_interface.h"
#include "ofono_modem.h"


class Ofono : public QObject
{
    Q_OBJECT
private:
    org::ofono::Manager *ofono;
    QList<OfonoModem *> *modemList;
    QDBusConnection *connection;
public:
    Ofono(QDBusConnection *connection);
public Q_SLOTS:
    unsigned int ModemCount();
    void onModemAdded(QDBusObjectPath path, QVariantMap properties);
Q_SIGNALS:
    void ModemAdded(QDBusObjectPath path);
};

#endif // OFONO_H