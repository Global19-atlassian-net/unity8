/*
 * Copyright (C) 2011, 2013 Canonical, Ltd.
 *
 * Authors:
 *  Florian Boucault <florian.boucault@canonical.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RATINGSFILTER_H
#define RATINGSFILTER_H

// Qt
#include <QObject>
#include <QMetaType>

// libunity-core
#include <UnityCore/RatingsFilter.h>

// Local
#include "filter.h"
#include "signalslist.h"

class GenericListModel;

class Q_DECL_EXPORT RatingsFilter : public Filter
{
    Q_OBJECT

    Q_PROPERTY(GenericListModel* options READ options NOTIFY ratingsChanged)

public:
    explicit RatingsFilter(QObject *parent = nullptr);

    /* getters */
    GenericListModel* options() const;

Q_SIGNALS:
    void ratingsChanged();

protected:
    virtual void setUnityFilter(unity::dash::Filter::Ptr filter);

protected Q_SLOTS:
    void onActiveChanged();

private:
    unity::dash::RatingsFilter::Ptr m_unityRatingsFilter;
    GenericListModel *m_options;
    SignalsList m_signals;
};

Q_DECLARE_METATYPE(RatingsFilter*)

#endif // RATINGSFILTER_H
