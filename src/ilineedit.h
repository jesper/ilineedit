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

#ifndef ILINEEDIT_H
#define ILINEEDIT_H

#include <QLineEdit>

class iLineEdit : public QLineEdit
{
public:
	iLineEdit(QWidget *parent = 0);
	iLineEdit(const QString &bgText, QWidget *parent = 0);

	void setBackgroundText(const QString& bgtext);
	QString backgroundText() const;

private:
  void paintEvent(QPaintEvent *event);

  QString m_bgText;
};
#endif
