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
#include <QStyleOptionFrameV2>

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

  const int margin = 2;

  QStyleOptionFrameV2 panel;
  initStyleOption(&panel);
  QRect r = style()->subElementRect(QStyle::SE_LineEditContents, &panel, this);
  QFontMetrics fm = fontMetrics();
  int horizontalMargin = this->x();
  QRect lineRect(margin + r.x(), r.y() + (r.height() - fm.height() + 1) / 2,
                 r.width() - 2 * margin, fm.height());

  QPainter painter(this);
  painter.setPen(Qt::gray);
  painter.drawText(lineRect, Qt::AlignLeft|Qt::AlignVCenter, m_bgText);
 
  painter.end();
}
