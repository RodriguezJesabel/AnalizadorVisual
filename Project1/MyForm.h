#pragma once

#include <fstream>
#include <cstdio>
#include <streambuf>
#include <regex>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;



// variables y declaraciones
string Analiza(string a);
string AbrirBoton(string filetl);
void Relaciona(char a);
int Token(int e, string token, string a);
int Error(int t);
void  GetToken();
string cadenaAnalizar;
int RelacionaToken(string token);
void estatutoAsig(string Token, string TokenTexto);
string existeVariable(string variable);
int cont_cadena_posicion = 0;
int Pila, ResultadosTokens;
string Tokens, pilaResultadoTokensTexto;
string Variables, VariablesTipo;

int M[27][32] = { {1,1,3,511,22,1,1,13,14,15,23,26,16,19,21,17,18,12,20,131,129,137,138,139,140,0,0,0,11,9,511,511},
				{1,1,1,2,100,1,1,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100},
				{1,1,1,2,500,1,1,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500},
				{101,101,3,101,4,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
				{501,501,5,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501},
				{102,102,5,102,102,6,6,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
				{502,502,8,502,502,502,502,7,7,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
				{503,503,8,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
				{103,103,8,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
				{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,504,504,10,10,507,504,504},
				{505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,104,505,505},
				{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,105,11,11,506},
				{106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,107,106,106,106,106,106,106,106,106,106,106,106,106,106,106},
				{108,108,108,108,108,108,108,110,108,108,108,108,108,108,108,108,108,109,108,108,108,108,108,108,108,108,108,108,108,108,108,108},
				{111,111,111,111,111,111,111,111,113,111,111,111,111,111,111,111,111,112,111,111,111,111,111,111,111,111,111,111,111,111,111,111},
				{114,114,114,114,114,114,114,114,114,116,114,114,114,114,114,114,114,115,114,114,114,114,114,114,114,114,114,114,114,114,114,114},
				{117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,118,117,117,117,117,117,117,117,117,117,117,117,117,117,117},
				{119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,120,119,119,119,119,119,119,119,119,119,119,119,119,119,119},
				{121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,122,121,121,121,121,121,121,121,121,121,121,121,121,121,121},
				{512,512,512,512,512,512,512,512,512,512,512,512,512,124,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512},
				{513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,126,513,513,513,513,513,513,513,513,513,513,513,513,513},
				{127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,128,127,127,127,127,127,127,127,127,127,127,127,127,127,127},
				{508,508,508,508,130,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508},
				{132,132,132,132,132,132,132,132,132,24,132,132,132,132,132,132,132,133,132,132,132,132,132,132,132,132,132,132,132,132,132,132},
				{24,24,24,24,24,24,24,24,24,25,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,510},
				{24,24,24,24,24,24,24,24,24,24,134,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,510},
				{26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,136,26,26,26,26,136} };

string tokenExitoso[] = { "Identificador",
					   "Constantes numérica entera",
					   "Constantes numérica real",
					   "Constantes numérica de notación científica",
					   "Constante carácter",
					   "Constante string",
					   "Operador de asignacion  = Igual",
					   "Operador Relacional == Es igual",
					   "Operador aritmético + Suma",
					   "Operador de asignacion += Adicion",
					   "Operador aritmético ++ Incremento",
					   "Operador aritmético - Resta",
					   "Operador de asignacion -= Sustraccion",
					   "Operador aritmético -- Decremento",
					   "Operador aritmético * Multiplicacion",
					   "Operador de asignacion *= ",
					   "Operador aritmético  ** ",
					   "Operador aritmético % Porcentaje",
					   "Operador de asignacion %=",
					   "Operador Relacional < Menor que",
					   "Operador Relacional <= Menor igual",
					   "Operador Relacional > Mayor que",
					   "Operador Relacional >= Mayor que",
					   "Operador lógico && And",
					   "Operador lógico || Or",
					   "Operador lógico ! Not",
					   "Operador Relacional != Diferente",
					   "Signo de puntacion ; Punto y coma",
					   "Signo de puntacion .. Punto punto",
					   "Signo de puntacion , coma",
					   "Operador aritmético / División",
					   "Operador de asignacion /=",
					   "Comentario /* */",
					   "Comentario # Simple",
					   "Signo de agrupacion [ Corchete que abre",
					   "Signo de agrupacion ] Corchete que cierra",
					   "Signo de agrupacion ( Parentesis que abre",
					   "Signo de agrupacion ) Parentesis que cierra",
					   "Fin del archivo" };
string tokenError[] = { "Identificador no puede terminar en '_' ",
					 "Dato numerico  no puede terminar en '.' esta se esperaba otro numero",
					 "Dato numerico  no puede terminar en 'E' o 'e' se esperaba otro numero o algún signo + o -",
					 "Dato numerico  no puede terminar en '+' o '-' se esperaba algun numero",
					 "Constante carácter debe contenter un elemento y terminar en comilla simple",
					 "Constante carácter debe en terminar en comilla simple",
					 "Constante string debe de terminar en  comillas dobles ",
					 "Constante carácter debe de contener al menos un carácter",
					 "Signo de puntacion esperaba un '.'",
					 "El comentario esperaba un '*/' para terminar",
					 "Carácter no reconocido",
					 "Operedor logico esperaba &",
					 "Operedor logico esperaba |" };
string palabrasResevadas[] = { "class",
							"endclass",
							"int",
							"float",
							"char",
							"string",
							"bool",
							"if",
							"else",
							"elseif",
							"endif",
							"do",
							"to",
							"eval",
							"enddo",
							"while",
							"endwhile",
							"read",
							"write",
							"def",
							"as",
							"for",
							"endfor",
							"private",
							"public",
							"void",
							"protected",
							"library",
							"func",
							"endfunc",
							"main",
							"endmain",
							"true",
							"false" };


string ErroresAnalisis[] = { "Inicio invalido, revise su entrada",
							"Archivo esta vacio",
							"Declaracion incorrecta, revise su sintaxis",
							"Debe existir un main",
							"Main, parametros incorrectos",
							"Declaracion de funcion incorecta",
							"Parametros incorrectos, revise su sintaxis",
							"Declaracion de varibles locales incorrecta",
							"Declaracion de id incorrecta",
							"Declaracion de arreglo incorrecto",
							"Declaracion incorrecta de la matriz",
							"Declaracion incorrecta de estatutos",
							"Declaracion incorrecta del estatuto do",
							"Declaracion incorrecta del estatuto for",
							"Declaracion incorrecta del estatuto if",
							"Declaracion incorrecta del elseif",
							"Declaracion incorrecta del else",
							"Declaracioin incorrecta del estatuto unit",
							"Declaracion incorrecta del estatuto asig",
							"Declaracion incorrecta del estatuto read",
							"Declaracion incorrecta del estatuto write",
							"Declaracion incorrecta del estatuto while",
							"Declaracion incorrecta del estatuto return",
							"Declaracion incorrecta de estatuto dimasig",
							"Declaracion incorrecta de term",
							"Declaracion Fact incorrecta",
							"Declaracion de llamada a funcion incorrecta",
							"Declaracion de expresion incorrecta",
							"Se esperaba un operador relacional",
							"Se esperaba un operador de asignacion",
							"Declaracion de acceso a variable incorrecta" };


string columnas[72][72] = { {"1000","library"},
						  {"1001","@este se me fue"},
						  {"1002",";"},
						  {"1003","class"},
						  {"1004","id"},
						  {"1005","endclass"},
						  {"1006","def"},
						  {"1007",","},
						  {"1008","as"},
						  {"1009","["},
						  {"1010","]"},
						  {"1011",".."},
						  {"1012","cteentera"},
						  {"1013","int"},
						  {"1014","float"},
						  {"1015","char"},
						  {"1016","string"},
						  {"1017","bool"},
						  {"1018","void"},
						  {"1019","public"},
						  {"1020","private"},
						  {"1021","protected"},
						  {"1022","main"},
						  {"1023","("},
						  {"1024",")"},
						  {"1025","endmain"},
						  {"1026","func"},
						  {"1027","endfunc"},
						  {"1028","local"},
						  {"1029","endlocal"},
						  {"1030","read"},
						  {"1031","write"},
						  {"1032","return"},
						  {"1033","++"},
						  {"1034","--"},
						  {"1035","for"},
						  {"1036","="},
						  {"1037","to"},
						  {"1038","do"},
						  {"1039","endfor"},
						  {"1040","while"},
						  {"1041","endwhile"},
						  {"1042","eval"},
						  {"1043","enddo"},
						  {"1044","if"},
						  {"1045","elseif"},
						  {"1046","else"},
						  {"1047","endif"},
						  {"1048","||"},
						  {"1049","&&"},
						  {"1050","!"},
						  {"1051","=="},
						  {"1052","!="},
						  {"1053","<"},
						  {"1054","<="},
						  {"1055",">"},
						  {"1056",">="},
						  {"1057","+"},
						  {"1058","-"},
						  {"1059","*"},
						  {"1060","/"},
						  {"1061","%"},
						  {"1062","ctereal"},
						  {"1063","ctenotacion"},
						  {"1064","ctecaracter"},
						  {"1065","ctestring"},
						  {"1066","+="},
						  {"1067","-="},
						  {"1068","*="},
						  {"1069","/="},
						  {"1070","%="},
						  {"1071","$"} };

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ PlainText;
	private: System::Windows::Forms::RichTextBox^ plainTextEdit_2;
	protected:

	protected:

	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PlainText = (gcnew System::Windows::Forms::RichTextBox());
			this->plainTextEdit_2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PlainText
			// 
			this->PlainText->Location = System::Drawing::Point(12, 96);
			this->PlainText->Name = L"PlainText";
			this->PlainText->Size = System::Drawing::Size(280, 265);
			this->PlainText->TabIndex = 0;
			this->PlainText->Text = L"";
			this->PlainText->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// plainTextEdit_2
			// 
			this->plainTextEdit_2->Location = System::Drawing::Point(467, 96);
			this->plainTextEdit_2->Name = L"plainTextEdit_2";
			this->plainTextEdit_2->Size = System::Drawing::Size(292, 265);
			this->plainTextEdit_2->TabIndex = 1;
			this->plainTextEdit_2->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(317, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 43);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Abrir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(317, 121);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 41);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Guardar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(317, 228);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 41);
			this->button3->TabIndex = 4;
			this->button3->Text = L"analizar ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(771, 373);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->plainTextEdit_2);
			this->Controls->Add(this->PlainText);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}


		   string AbrirBoton(string archive) {
			   //ABRIR ARCHIVO
			   ifstream archivo;
			   string info;
			   char character;

			   archivo.open(archive);
			   if (!archivo) {
				   cout << "El archivo no se ha abierto" << endl;
				   exit(1);
			   } while (archivo.get(character)) {
				   info.push_back(character);
			   }
			   archivo.close();

			   return info;
		   }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		string AbrirBoton(string filetl);

	}



	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//Tipo de archivo a guardar

	}



		   int relaciona(char c) {
			   //Caso numero
			   if (c >= '0' && c <= '9') {
				   return 2;
			   }
			   //Caso caracteres conocidos
			   switch (c)
			   {
			   case '_': return 3;
			   case '.': return 4;
			   case 'E': return 5;
			   case 'e': return 6;
			   case '+': return 7;
			   case '-': return 8;
			   case '*': return 9;
			   case '/': return 10;
			   case '#': return 11;
			   case '%': return 12;
			   case '&': return 13;
			   case '!': return 14;
			   case '<': return 15;
			   case '>': return 16;
			   case '=': return 17;
			   case '|': return 18;
			   case ',': return 19;
			   case ';': return 20;
			   case '[': return 21;
			   case ']': return 22;
			   case '(': return 23;
			   case ')': return 24;
			   case '"': return 25;
			   case '\n': return 26;
			   case '\t': return 27;
			   case '\0': return 28;
			   }


			   //Caso letras
			   if ((int(c) >= 97 && int(c) <= 122) || (int(c) >= 65 && int(c) <= 90))
			   {
				   return 0;
			   }
			   //Caso comilla simple
			   switch (int(c)) {
			   case 39: return 29;
			   }
			   //Caso diferente
			   return 30;
		   }


		   int Token(int e, String token)
		   {
			   switch (e)
			   {
			   case 100: return  0;
			   case 101: return  1;
			   case 102: return  2;
			   case 103: return  3;
			   case 104: return  4;
			   case 105: return  5;
			   case 106: return  6;
			   case 107: return  7;
			   case 108: return  8;
			   case 109: return  9;
			   case 110: return  10;
			   case 111: return  11;
			   case 112: return  12;
			   case 113: return  13;
			   case 114: return  14;
			   case 115: return  15;
			   case 116: return  16;
			   case 117: return  17;
			   case 118: return  18;
			   case 119: return  19;
			   case 120: return  20;
			   case 121: return  21;
			   case 122: return  22;
			   case 124: return  23;
			   case 126: return  24;
			   case 127: return  25;
			   case 128: return  26;
			   case 129: return  27;
			   case 130: return  28;
			   case 131: return  29;
			   case 132: return  30;
			   case 133: return  31;
			   case 134: return  32;
			   case 136: return  33;
			   case 137: return  34;
			   case 138: return  35;
			   case 139: return  36;
			   case 140: return  37;
			   case 144: return  38;
			   }
			   return 100;
		   } //fin de token




		   string analiza(string a) {

			   int edo;
			   int col;
			   char car;
			   int cont_cadena = 0;
			   string a;
			   string cadena;
			   char* cstr = &cadena[cont_cadena];
			   string resultado = "";
			   string cadenaResultante;
			   string identificador;
			   string r;
			   int T;
			   bool AnalisisCorrecto = true;
			   if (a.length() > 0) {
				   while (cont_cadena <= (a.length()))
				   {
					   //Se reinician variables
					   edo = 0;
					   cadenaResultante = "", identificador = "";
					   while (edo <= 26)
					   {
						   car = (char)cstr[cont_cadena];
						   col = relaciona(car);
						   edo = M[edo][col];
						   //Terminaron con la letra correspondiente
						   if (edo == 104 || edo == 105 || edo == 107 || edo == 109 || edo == 110 || edo == 112 || edo == 113 || edo == 115 || edo == 116 || edo == 120 || edo == 122 || edo == 123 || edo == 124 || edo == 126 || edo == 126 || edo > 127) {
							   cadenaResultante = cadenaResultante + "" + car;
						   }//Terminaron con dif, deja el elemento que lo termino para volver a analizarlo
						   else if (edo == 100 || edo == 101 || edo == 102 || edo == 103 || edo == 106 || edo == 108 || edo == 111 || edo == 114 || edo == 117 || edo == 119 || edo == 121 || edo == 127) {
							   cont_cadena--;;
						   }
						   if (edo < 27) {
							   //Omitimos a los delimitadores
							   if (edo != 0 && car != '\n' && car != '\b' && car != '\t' && car != ' ' && car != '\0') {
								   cadenaResultante = cadenaResultante + "" + car + "";
							   }
							   cont_cadena++;
						   }

					   }
					   //concatenamos resultado de analisis
					   resultado += cadenaResultante;
					   if (edo >= 100 && edo <= 144)
					   {
						   //Respaldamos el valor de nuestra cadena antes de asiganrle el resultado de su token correspondiente
						   identificador = cadenaResultante;
						   T = Token(edo, identificador);
						   cadenaResultante = tokenExitoso[T]; //Obtiene la cadena correspondiente al estado al que llego
						   //Analisis para detectar si el identificador pertenece a las palabras reservadas
						   if (edo == 100) {
							   for (int rPR = 0; rPR < 32; rPR++) {
								   if (identificador.compare(palabrasResevadas[rPR]) == 0)
								   {
									   cadenaResultante = "Palabra Reservada";
									   rPR = 33;
								   }
							   }

						   }
					   }
					   else
					   {
						   T = Error(edo);
						   cadenaResultante = tokenError[T]; //Obtiene la cadena correspondiente al estado al que llego
						   AnalisisCorrecto = false;
						   cont_cadena = a.size();
					   }
					   resultado += " -> " + cadenaResultante + "\n";
					   cont_cadena++;
					   if (!AnalisisCorrecto) {
						   resultado += " - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
							   "      Análisis Finalizado se encontraron \n"
							   "                        Errores\n"
							   " - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
						   //Ponemos resultados en la pantalla
						   r = string(resultado);
						   // @Aqui, no se como poner este resultado en pantalla, y en los que siguen tampoco pues
						   break;
					   }
					   else if (AnalisisCorrecto && cont_cadena >= a.length()) {
						   resultado += " - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
							   "      Análisis Finalizado Correctamente\n"
							   " - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
						   //Ponemos resultados en la pantalla
						   r = string(resultado);
						   plainTextEdit_2.show(r);
						   break;
					   }
					   //Ponemos resultados en la pantalla
					   r = string(resultado);
					   plainTextEdit_2t.show(r);
				   }
			   }
			   else {
				   resultado += " - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
					   "            Sin datos para analizar\n"
					   " - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
				   //Ponemos resultados en la pantalla
				   r = string(resultado);



			   }
		   }

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		string Analiza(string a);


	}

		   void GetToken() {
			   int edo, col;
			   char car;
			   string cadena = cadenaAnalizar;
			   char* cstr = &cadena[cont_cadena_posicion];
			   string resultado = "";
			   string cadenaResultante, identificador;
			   string r;
			   int T = 0;
			   bool AnalisisCorrecto = true;
			   if (cadenaAnalizar.length() > 0) {
				   while (cont_cadena_posicion <= (cadenaAnalizar.length()))
				   {
					   //Se reinician variables
					   edo = 0;
					   cadenaResultante = "", identificador = "";
					   while (edo <= 26)
					   {
						   car = (char)cstr[cont_cadena_posicion];
						   col = relaciona(car);
						   edo = M[edo][col];
						   //Terminaron con la letra correspondiente
						   if (edo == 104 || edo == 105 || edo == 107 || edo == 109 || edo == 110 || edo == 112 || edo == 113 || edo == 115 || edo == 116 || edo == 120 || edo == 122 || edo == 123 || edo == 124 || edo == 126 || edo == 126 || edo > 127) {
							   cadenaResultante = cadenaResultante + "" + car;
						   }//Terminaron con dif, deja el elemento que lo termino para volver a analizarlo
						   else if (edo == 100 || edo == 101 || edo == 102 || edo == 103 || edo == 106 || edo == 108 || edo == 111 || edo == 114 || edo == 117 || edo == 119 || edo == 121 || edo == 127) {
							   cont_cadena_posicion--;;
						   }
						   if (edo < 27) {
							   //Omitimos a los delimitadores
							   if (edo != 0 && car != '\n' && car != '\b' && car != '\t' && car != ' ' && car != '\0') {
								   cadenaResultante = cadenaResultante + "" + car + "";
							   }
							   cont_cadena_posicion++;
						   }

					   }
					   //concatenamos resultado de analisis
					   resultado += cadenaResultante;
					   if (edo >= 100 && edo <= 144)
					   {
						   //Respaldamos el valor de nuestra cadena antes de asiganrle el resultado de su token correspondiente
						   identificador = cadenaResultante;
						   Tokens.push_back(identificador);
						   T = Token(edo, identificador);//@ aqui no se que pase, y error se repite depues
						   cadenaResultante = tokenExitoso[T]; //Obtiene la cadena correspondiente al estado al que llego
						   //Analisis para detectar si el identificador pertenece a las palabras reservadas
						   if (edo == 100) {
							   for (int rPR = 0; rPR < 32; rPR++) {
								   if (identificador.compare(palabrasResevadas[rPR]) == 0)
								   {

									   cadenaResultante = palabrasResevadas[rPR];
									   rPR = 33;
								   }
							   }

						   }
						   pilaResultadoTokens.push_back(edo); //@@No supe donde y como meter la conversion de std a string
						   pilaResultadoTokensTexto.push_back(cadenaResultante);
					   }
					   else
					   {
						   T = Error(edo);
						   cadenaResultante = tokenError[T]; //Obtiene la cadena correspondiente al estado al que llego
						   AnalisisCorrecto = false;
						   cont_cadena_posicion = cadenaAnalizar.size();
					   }

					   ResultadosTokens.push_back(edo); //@@ nose :(

					   resultado += " -> " + cadenaResultante + "\n";
					   cont_cadena_posicion++;
					   if (!AnalisisCorrecto) {
						   break;
					   }
					   else if (AnalisisCorrecto && cont_cadena_posicion >= cadenaAnalizar.length()) {
						   break;
					   }
				   }
			   }
		   }
		   int RelacionaToken(string token) {
			   if (ResultadosTokens.top() < 500) { // @ No se si sepas el equivalente de .top() en visual
				   for (int x = 0; x < 72; x++) {
					   if (token.compare(columnas[x][1]) == 0)
					   {
						   int r = stoi(columnas[x][0]);
						   return r;
					   }
				   }
				   if (ResultadosTokens.top() == 100) {
					   return 1004;
				   }
				   else if (ResultadosTokens.top() == 101) {
					   return 1012;
				   }
				   else if (ResultadosTokens.top() == 102) {
					   return 1062;
				   }
				   else if (ResultadosTokens.top() == 103) {
					   return 1063;
				   }
				   else if (ResultadosTokens.top() == 104) {
					   return 1064;
				   }
				   else if (ResultadosTokens.top() == 105) {
					   return 1065;
				   }
				   else if (ResultadosTokens.top() == 134) {
					   return 1080;
				   }
				   else if (ResultadosTokens.top() == 136) {
					   return 1080;
				   }
			   }

			   return -1;
		   }


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


	}