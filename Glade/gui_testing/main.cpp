//g++ main.cpp -o base `pkg-config --cflags --libs gtk+-3.0 gmodule-2.0`

#include <gtk/gtk.h>

static void on_entrySwathSize_activate(GtkWidget *widget, gpointer *data)
{
	g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(data)));
}

static void on_buttonProperties_clicked(GtkWidget *widget, gpointer *data)
{
	gtk_widget_show(GTK_WIDGET(data));
}

static void on_buttonApplyProperties_clicked(GtkWidget *widget, gpointer *data)
{
	gtk_widget_hide(GTK_WIDGET(data));
	g_print("Properties modified.\n");
}

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	GtkBuilder *gtkBuilder;
	//windows
	GtkWidget *windowMain, *windowProperties;
	//entries
	GtkWidget *entrySwathSize;
	//buttons
	GtkWidget *buttonApplyProperties, *buttonProperties;	
	
	gtkBuilder = gtk_builder_new();
	gtk_builder_add_from_file(gtkBuilder, "rdp_gui.glade", NULL);
	
	windowMain = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "windowMain"));
	windowProperties = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "windowProperties"));
	
	entrySwathSize = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "entrySwathSize"));
	buttonApplyProperties = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "buttonApplyProperties"));
	buttonProperties = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "buttonProperties"));
	
	g_signal_connect(windowMain, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(windowProperties, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	
	g_signal_connect(entrySwathSize, "activate", G_CALLBACK(on_entrySwathSize_activate), entrySwathSize);	
	g_signal_connect(buttonProperties, "clicked", G_CALLBACK(on_buttonProperties_clicked), windowProperties);
	g_signal_connect(buttonApplyProperties, "clicked", G_CALLBACK(on_buttonApplyProperties_clicked), windowProperties);
	
	gtk_widget_show_all(windowMain);
	gtk_main();
	
	return 0;
}
