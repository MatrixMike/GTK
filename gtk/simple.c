/* GTK - The GIMP Toolkit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA  02111-1307, USA.
 */
#include <gtk/gtk.h>
#include <gdk/gdkprivate.h>


void
hello (void)
{
  g_print ("hello world\n");
}

int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;

  gdk_progclass = g_strdup ("XTerm");
  gtk_init (&argc, &argv);

  window = gtk_widget_new (gtk_window_get_type (),
			   "GtkObject::user_data", NULL,
			   "GtkWindow::type", GTK_WINDOW_TOPLEVEL,
			   "GtkWindow::title", "hello world",
			   "GtkWindow::allow_grow", FALSE,
			   "GtkWindow::allow_shrink", FALSE,
			   "GtkContainer::border_width", 10,
			   NULL);
  button = gtk_widget_new (gtk_button_get_type (),
			   "GtkButton::label", "hello world",
			   "GtkObject::signal::clicked", hello, NULL,
			   "GtkWidget::parent", window,
			   "GtkWidget::visible", TRUE,
			   NULL);
  gtk_widget_show (window);

  gtk_main ();

  return 0;
}
