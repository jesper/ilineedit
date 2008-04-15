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

#include <QApplication>
#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>

#include "ilineedit.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  
  QDialog *dia = new QDialog;
  dia->setLayout(new QBoxLayout(QBoxLayout::TopToBottom, dia));

  dia->layout()->addWidget(new iLineEdit("First Name", dia));
  dia->layout()->addWidget(new iLineEdit("Last Name", dia));
  dia->layout()->addWidget(new QPushButton("Profit!", dia));
  
  dia->show();
  
  return app.exec();
}
