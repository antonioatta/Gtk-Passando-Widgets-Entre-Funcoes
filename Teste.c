#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void Teste2(GtkWidget *);

void Teste3(GtkWidget *Button, GtkWidget *[]);


int main (int argc, char *argv[]){
	GtkBuilder *builder;
	GtkWidget *proximo, *Janela1;

	gtk_init(&argc, &argv);
	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "Teste 1.glade", NULL);

	Janela1 = GTK_WIDGET(gtk_builder_get_object(builder, "Janela1"));
	proximo = GTK_WIDGET(gtk_builder_get_object(builder, "Proximo"));

	g_signal_connect(proximo, "clicked", G_CALLBACK (Teste2), proximo);

	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show_all(Janela1);

	gtk_main();

	return 0;
}

void Teste2(GtkWidget *Button){
	GtkBuilder *builder;
	GtkWidget *entrada1, *entrada2, *entrada3 , *proximo2 ,*Janela2;
	static GtkWidget *Widgets[3];

	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "Teste 2.glade", NULL);

	Janela2 = GTK_WIDGET(gtk_builder_get_object(builder, "Janela2"));
	entrada1 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada1"));
	entrada2 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada2"));
	entrada3 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada3"));
	proximo2 = GTK_WIDGET(gtk_builder_get_object(builder, "Proximo2"));

	Widgets[0] = entrada1;
	Widgets[1] = entrada2;
	Widgets[2] = entrada3;

	//conectando os widgets carregados nesta funcao à funcao teste, com o evento clickar no botão próximo.
	g_signal_connect(proximo2, "clicked", G_CALLBACK (Teste3), Widgets);

	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show_all(Janela2);

}

void Teste3(GtkWidget *Button, GtkWidget *Widgets[]){
	GtkBuilder *builder;
	GtkWidget *entrada4, *entrada5, *entrada6 , *Janela3;

	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "Teste 3.glade", NULL);

	Janela3 = GTK_WIDGET(gtk_builder_get_object(builder, "Janela3"));
	entrada4 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada4"));
	entrada5 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada5"));
	entrada6 = GTK_WIDGET(gtk_builder_get_object(builder, "Entrada6"));

	//ao tenta pegar os textos dos campos o programa dará segmentation fault.
	gtk_entry_set_text(GTK_ENTRY(entrada4), gtk_entry_get_text(GTK_ENTRY(Widgets[0])));
	gtk_entry_set_text(GTK_ENTRY(entrada5), gtk_entry_get_text(GTK_ENTRY(Widgets[1])));
	gtk_entry_set_text(GTK_ENTRY(entrada6), gtk_entry_get_text(GTK_ENTRY(Widgets[2])));


	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show_all(Janela3);
}
