//g++ main.cpp -o base `pkg-config --cflags --libs gtk+-3.0 gmodule-2.0`

#include <gtk/gtk.h>

static void on_entryRefSigSize_activate(GtkWidget *widget, gpointer *data)
{
	g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
}

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	GtkBuilder *gtkBuilder;
	GtkWidget *windowMain, *entryRefSigSize, *buttonExit;	
	
	gtkBuilder = gtk_builder_new();
	gtk_builder_add_from_file(gtkBuilder, "simple_gui.glade", NULL);
	
	windowMain = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "mainWindow"));
	entryRefSigSize = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "entryRefSigSize"));
	buttonExit = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "buttonExit"));
	
	g_signal_connect(windowMain, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(entryRefSigSize, "activate", G_CALLBACK(on_entryRefSigSize_activate), entryRefSigSize);
	g_signal_connect(buttonExit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_widget_show_all(windowMain);
	gtk_main();
	
	return 0;
}
