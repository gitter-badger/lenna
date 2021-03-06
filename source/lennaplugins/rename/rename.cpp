/**
    This file is part of program Lenna
    Copyright (C) 2013-2016 FalseCAM

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "rename.h"
#include <QtGui/QPainter>
#include "widget.h"

using namespace lenna;
using namespace lenna::plugin::rename;

Rename::Rename() { widget = 0; }

Rename::~Rename() {}

QString Rename::getName() { return QString("rename"); }

QString Rename::getTitle() { return QString(tr("Rename")); }

QString Rename::getVersion() { return QString("0.1"); }

QString Rename::getAuthor() { return QString("FalseCAM"); }

QString Rename::getDescription() {
  return QString(tr("Plugin to rename image files"));
}

QIcon Rename::getIcon() { return QIcon(":/plugins/rename/rename"); }

QWidget *Rename::getWidget() {
  if (!this->widget) {
    this->widget = new Widget();
  }
  return this->widget;
}

void Rename::edit(std::shared_ptr<LennaImage> img) {
  getWidget();
  if (widget->isRename()) {
    QString name = widget->prefix();
    if (widget->isNewName()) {
      name.append(widget->newName());
    } else {
      name.append(img->getName());
    }
    name.append(widget->suffix());
    img->setName(name);
  }
}
