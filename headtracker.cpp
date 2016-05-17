/*
 * Copyright (c) 2016 Shawn Rutledge
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "headtracker.h"

#include <QDebug>

static void trackerCallback(void * tracker,
                       const OSVR_TimeValue *ts,
                       const OSVR_PoseReport *report) {
//    qDebug() << "Got POSE report: Position = ("
//              << report->pose.translation.data[0] << ", "
//              << report->pose.translation.data[1] << ", "
//              << report->pose.translation.data[2] << "), orientation = ("
//              << osvrQuatGetW(&(report->pose.rotation)) << ", ("
//              << osvrQuatGetX(&(report->pose.rotation)) << ", "
//              << osvrQuatGetY(&(report->pose.rotation)) << ", "
//              << osvrQuatGetZ(&(report->pose.rotation)) << "))";
    emit static_cast<HeadTracker *>(tracker)->poseChanged(
            report->pose.translation.data[0],
            report->pose.translation.data[1],
            report->pose.translation.data[2],
            osvrQuatGetW(&(report->pose.rotation)),
            osvrQuatGetX(&(report->pose.rotation)),
            osvrQuatGetY(&(report->pose.rotation)),
            osvrQuatGetZ(&(report->pose.rotation)) );
}

HeadTracker::HeadTracker(QObject *parent) :
    QObject(parent),
    m_context("com.osvr.exampleclients.TrackerCallback"),
    m_head(m_context.getInterface("/me/head"))
{
    m_head.registerCallback(&trackerCallback, this);
}

void HeadTracker::update()
{
    m_context.update();
}
