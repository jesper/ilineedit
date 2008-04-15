/*
    Author: Jesper Thomschutz 2008, jesper@jespersaur.com

    This file is part of iLineEdit.

    iLineEdit is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    iLineEdit is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with iLineEdit.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QLineEdit>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

#include "ilineedit.h"

iLineEdit::iLineEdit(QWidget *parent) 
	: QLineEdit(parent)
{
}

iLineEdit::iLineEdit(const QString &bgText, QWidget *parent) 
	: QLineEdit(parent), m_bgText(bgText)
{
}

void iLineEdit::setBackgroundText(const QString &bgText)
{
  m_bgText = bgText;
}

QString iLineEdit::backgroundText() const
{
  return m_bgText;
}

void iLineEdit::paintEvent(QPaintEvent *event)
{
  QLineEdit::paintEvent(event);
  
  if (!text().isEmpty())
    return;
  
  QPainter painter;
  painter.begin(this);
  painter.setPen(Qt::gray);

  const int margin = 6;
  QRect r = rect();
  r.adjust(margin, 0, -margin, 0);
  painter.drawText(r, Qt::TextSingleLine|Qt::AlignLeft|Qt::AlignVCenter, m_bgText);
  painter.end();
}
