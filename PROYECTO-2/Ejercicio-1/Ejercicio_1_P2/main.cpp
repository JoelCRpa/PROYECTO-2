#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



using namespace std;


	// devuelve el año actual
	int MuestraAnioActual(){		
		std::time_t tiempoActual = std::time(NULL);	    
	    std::tm* fechaActual = std::localtime(&tiempoActual); // Convertir a estructura tm 
	    int anioActual = 1900 + fechaActual->tm_year; // Obtinene el año actual
		return anioActual;
	}	
	const int Anio_Actual=MuestraAnioActual();
	const int EstadisticasEstudiantes[]={0};
	
	int Total_admitidos=0;
	int Total_Noadmitidos=0;
	int Total_EnEspera=0;
	
	// calcula el promedio del colegio
	float PromedioColegio(int Promedio1,int Promedio2,int Promedio3,int Promedio4 ){		
		float PromedioFinal=0;
		
		PromedioFinal=(Promedio1+Promedio2+Promedio3+Promedio4)/4;
		
		return PromedioFinal;	
	}
	//calculo de calificacion si es admitido o no
	string Calificacion(float PromedioAdmision){
		string Calificacion="";

		if(PromedioAdmision>=85){
			Calificacion="ADMITIDO";
			Total_admitidos++;
		}	
		else if(PromedioAdmision >= 75 && PromedioAdmision < 85){
			Calificacion="EN ESPERA";
			Total_EnEspera++;
		}	
		else if(PromedioAdmision < 75){
			Calificacion="NO ADMITIDO";
			Total_Noadmitidos++;
		}
	 return Calificacion;
	}
	
	
	


	void IngresarDatos(){
		setlocale(LC_ALL, "");
		system("cls");
		int CantEstud_a_Ingresar=0;
		printf("\n ¿Cuántos estudiantes desea ingresar? ");
		cin>>CantEstud_a_Ingresar;
		char eleccion;
		int cedula[CantEstud_a_Ingresar]={0};
		string nombreEstudiante[CantEstud_a_Ingresar];
		int PromedioMate;
		int PromedioEstudiosSoc;
		int PromedioEspaniol;
		int PromedioCiencias;
		int contador=0;
		int anioNacimiento[CantEstud_a_Ingresar];
		int edad[CantEstud_a_Ingresar]={0};
		int ContadorEstudiante=0;
		float PromediosGrales[CantEstud_a_Ingresar]={0};
		float Porc_CriterioColegio[CantEstud_a_Ingresar]={0};
		float Porc_ExamenAdmision[CantEstud_a_Ingresar]={0};
		float NotaExamenAdmi[CantEstud_a_Ingresar]={0};
		float PromedioAdmision[CantEstud_a_Ingresar]={0};
		string CalificacionEstudiante[CantEstud_a_Ingresar];
			
		
		do{
			system("cls");
			printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++");
			printf("\n\tIngreso de datos    |     Estudiante # %i\n",ContadorEstudiante+1);
			printf(" ++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\nDigite su cédula: ");
			scanf("%i",&cedula[ContadorEstudiante]);
			fflush(stdin);			
			printf("\nDigite su Nombre: ");
			getline(cin,nombreEstudiante[ContadorEstudiante]);//lee una linea completa y lo guarda en el vector de string			
			fflush(stdin);
			printf("\nDigite el anio de nacimiento: ");
		    scanf("%i",&anioNacimiento[ContadorEstudiante]);
			fflush(stdin);
			printf("\nIngrese la nota obtenida en el examen de admisión: ");
		    scanf("%f",&NotaExamenAdmi[ContadorEstudiante]);
			fflush(stdin);
			
		    edad[ContadorEstudiante]=Anio_Actual-anioNacimiento[ContadorEstudiante];// calculo de edad
			
			printf("\n==========================================");
			printf("\nIngrese el promedio finales de las siguientes materias: \n");
			printf("\nMatemáticas: ");
			scanf("%i",&PromedioMate);fflush(stdin);
			printf("\nEspaniol: ");
			scanf("%i",&PromedioEspaniol);fflush(stdin);
			printf("\nCiencias: ");
			scanf("%i",&PromedioCiencias);fflush(stdin);
			printf("\nEstudios Sociales: ");
			scanf("%i",&PromedioEstudiosSoc);fflush(stdin);
		
			// calculo de promedio del colegio
			PromediosGrales[ContadorEstudiante]= PromedioColegio(PromedioMate,PromedioEspaniol,PromedioCiencias,PromedioEstudiosSoc);
			//Calcula el Porcentaje de Criterio Colegio 
			Porc_CriterioColegio[ContadorEstudiante]=PromediosGrales[ContadorEstudiante]*0.40;
			//Calcula porcentaje de EXAMEN admision
			Porc_ExamenAdmision[ContadorEstudiante]=NotaExamenAdmi[ContadorEstudiante]*0.60;
			// calcula el promedio de admision
			PromedioAdmision[ContadorEstudiante]=Porc_CriterioColegio[ContadorEstudiante]+Porc_ExamenAdmision[ContadorEstudiante];
			// indica por medio de un metodo si esta admitido, espera, o no admitido
			CalificacionEstudiante[ContadorEstudiante]=Calificacion(PromedioAdmision[ContadorEstudiante]);
			
					
			ContadorEstudiante++;
			contador++;
			
			if (ContadorEstudiante==CantEstud_a_Ingresar){	// valida cuando llega a la cantidad deseada y termina el bucle
				break;
			}			
			cout<<"\n ¿desea continuar ingresando los demás estudiantes? (s/n): ";	
			cin>>eleccion;
			if (eleccion=='n'){	
				break;
			}	
		}while(eleccion!='n');	
				
		system("cls");
		cout<<endl<<"---------------------------------"<<endl;	
			for(int i=0;i<CantEstud_a_Ingresar;i++){
				for (int j=0;j<1;j++){
					if(cedula[i]!=0){
						cout<<"Estudiante : "<<i+1<<endl;
						cout<<"cedula: "<< cedula[i] <<endl;
						cout<<"Nombre: "<< nombreEstudiante[i] <<endl;
						cout<<"Edad "<< edad[i] <<endl;
						cout<<"Promedio "<<PromediosGrales[i]<<endl;
						cout<<"Porcentaje de criterio: "<<Porc_CriterioColegio[i]<<endl;
						cout<<"Porcentaje examen de admisión: "<<Porc_ExamenAdmision[i]<<endl;
						cout<<"Promedio admisión: "<<PromedioAdmision[i]<<endl;
						cout<<"Resultado Calificación: "<<CalificacionEstudiante[i]<<endl;
					}						
				}	
			 cout<<"................................"<<endl;	
			}
		getch();			
	}
	
	
	
void 	Estadisticas(){
		cout<<endl<<"ESTADISTICAS	"<<endl;
		cout<<"Total Admitidos: "<<Total_admitidos<<endl;
		cout<<"Total No Admitidos: "<<Total_Noadmitidos<<endl;
		cout<<"Total En espera: "<<Total_EnEspera<<endl;
}

	void Menu(){
			setlocale(LC_ALL, "");
		int op;
		do{			
			system("cls");
			printf("\n==========================================");
			printf("\nSISTEMA DE INGRESO UTC\n");
			printf("==========================================\n\n\n\n");			
			printf("-Opcion 1: IngresarDatos\n");
			printf("-Opcion 2: Estadísticas\n");
			printf("-Opcion 3: Gráfico\n");
			printf("-Opcion 4: Salir\n");
			printf("\nDigite una opción: ");
			scanf("%i",&op);
			
			switch (op)
			{
				case 1:
					IngresarDatos();
				break;
				case 2:
					Estadisticas();
					getch();
				break;
				case 3:					
				break;
			}
		
		}while(op!=4);						
	}

int main(int argc, char** argv) {
	Menu();
	return 0;
}
