/*                                             SIMULACION DEL JUEGO DOMINO DE DOS JUGADORES 
ESTUDIANTES: Daniela Jhanin Callata Bautista
             Franz Choque Quispe
CARRERA: Ingenieria Electronica
                                    LABORATORIO 3
*/
#include<iostream>
#include<math.h>

using namespace std; 

void opciones(){
	cout<<"\nPresione 1 \tHallar la Suma"<<endl;
	cout<<"Presione 2 \tHallar la Resta"<<endl;
	cout<<"Presione 3 \tHallar la Multiplicacion"<<endl;	
	cout<<"Presione 4 \tHallar la Division de matrices"<<endl;
	cout<<"Presione 5 \tHallar el determinante"<<endl;
	cout<<"Presione 6 \tHallar la inversa"<<endl;
	cout<<"Presione 7 \tHallar la transpuesta"<<endl;
	cout<<"Presione 8 \tHallar el Rango"<<endl;
	cout<<"Presione 9 \tMultiplicar por un escalar"<<endl;
	cout<<"Presione 10 \tHallar la matriz triangular"<<endl;
	cout<<"Presione 11 \tHallar la matriz diagonal"<<endl;
	cout<<"Presione 12 \tElevar una matriz a un exponente"<<endl;
	cout<<"Presione 13 \tFactorizacion LU"<<endl;
	cout<<"Presione 14 \tFactorizacion de Cholnsky"<<endl;
	cout<<"Presione 15 \tHallar sus valores propios"<<endl;
	cout<<"Presione 16 \tHallar vectores propios"<<endl;
	cout<<"Presione 17 \tReescribir las matrices"<<endl;
	cout<<"Presione 18 \tSalir"<<endl;
}

void elegirLaMatriz(){
	cout<<"\nPresione 1 Para hallar de la matriz 1"<<endl;
	cout<<"Presione 2 Para hallar de la matriz 2"<<endl;
	cout<<"Presione 3 Para salir"<<endl;
} 

void resolverEcuacion2Grado(float ,float , float ,float&,float&);

void resolverEcuacion2Grado(float a, float b, float c, float& x1, float& x2){
	
	float d=0,imag=0;

	if(a==0) 
	{
		if(a==0 and b==0 and c==0)
			{
				cout<<"\nLa ecuacion tiene infinitas soluciones"<<endl;
			}
		else
		{
			x1 = -c/b;
			x2 = x1;
			cout<<"Solo existe una solucion para x"<<endl;
			cout<<"El valor de x que satisface la ecuacion es: x="<<x1<<endl;		
		}
	}
	else
	{ 
		d = (pow(b,2))-(4*a*c);
	
		if(d<0)
		{
			imag = (sqrt(-d))/(2*a);
			x1 = (-b/(2*a));
			x2 = x1;
			
			cout<<"\nSu ecuacion tiene dos soluciones imaginarias";
			cout<<"\nEl primer valor que satisface la ecuacion es: x1="<<x1<<"+"<<imag<<"i";
			cout<<"\nEl segundo valor que satisface la ecuacion es: x2="<<x2<<"-"<<imag<<"i";
		}
		else
		{
			x1 = (-b+sqrt(d))/(2*a);
			x2 = (-b-sqrt(d))/(2*a);
		
		}
	}	
	

}

void resolverEcuacion3Grado(float, float , float, float , float&, float&, float&);

void resolverEcuacion3Grado(float a, float b, float c, float d, float& x1, float& x2, float& x3){
	
	float z,dis,p,q,k,h,m,n,g,imag,pi;
	float u,v;
	
	pi = 3.14159265359;
	
	if(a==0 and b==0 and c==0 and d==0)
	{
		cout<<"\nLa ecuacion tiene infinitas soluciones"<<endl;
	}
	
	p = (c/a)-((pow(b/a,2))/3);
	q = (d/a)-((b*c)/(3*(pow(a,2))))+(((pow(b/a,3))*2)/27);
	dis = (pow(q,2)/4)+(pow(p,3)/27);
		
	if(dis<0)
	{
		x1 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt(-27/(pow(p,3))))/3) -((b/a)/3);
    	x2 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(pow(p,3))))/3 +2*pi/3) -((b/a)/3);
    	x3 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(pow(p,3))))/3 +4*pi/3) -((b/a)/3);
    	
    	cout<<"\nLa ecuacion tiene 3 soluciones reales: "<<endl;
    	cout<<"x1="<<x1<<endl;
    	cout<<"x2="<<x2<<endl;
    	cout<<"x3="<<x3<<endl;
	}
	
	if(dis>=0)
	{
		h = (-q/2)-sqrt(dis);
		m = (-q/2)+sqrt(dis);
		
		if(h<0)
		{
			k = h*(-1);
			v = pow(k,1.0/3.0);	
			v = v*(-1);
		}
		else
		{
			v = pow(h,1.0/3.0);		
		}
		
		if(m<0)
		{
			n = m*(-1);
			u = pow(n,1.0/3.0);
			u = u*(-1);
		}
		else
		{
			u = pow(m,1.0/3.0);
		}
		
		x1 = u+v-(b/(3*a));
		x2 = -0.5*(u+v)-(b/(3*a));
		x3 = x2;
		imag = 0.5*sqrt(3)*(u-v);
		
		if(imag==0 and x1==x2)
		{
			cout<<"\nLa ecuacion tiene tres raices iguales: "<<endl;
			cout<<"x1=x2=x3="<<x1<<endl;
		}
		else
		{	
			cout<<"\nLa ecuacion tiene 3 soluciones"<<endl;
	    	cout<<"x1="<<x1<<endl;
	    	cout<<"x2="<<x2<<"+"<<imag<<"i"<<endl;
	    	cout<<"x3="<<x3<<"-"<<imag<<"i"<<endl;	
		}	
	}
}


int main(){
	
	int nMatriz, opcion, filas1, columnas1, filas2, columnas2,sum, h, i, j, k, n=1, m=1, reescribir=0;
	float a,b=0, aux, pivote, pivote1, det, escalar, exponente;
	float paraDiagonal1, paraDiagonal2, paraDiagonal3, paraDiagonal4;
	float autovalor1, autovalor2, autovalor3;
	float autovector1, autovector2, autovector3, autovector4, autovector5;
	float autovector6, autovector7, autovector8, autovector9,ejemplo;
	float termino1, termino2, termino3, termino4, termino5, termino6,comprobar,comprobar1;
	float ejemplo1[3][3];
	float ejemplo2[4][2];
	
	do{	
		
		reescribir = 0;
		
		cout<<"Ingrese el tamaño de la matriz 1"<<endl;
		cout<<"Ingrese el numero de filas de la matriz 1: "; cin>>filas1;
		cout<<"Ingrese el numero de columnas de la matriz 1: "; cin>>columnas1;
			
		float matriz1[filas1][columnas1];
			
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
					
				matriz1[i][j] = 0;
			}
		}
			
		cout<<"Ingrese los terminos de la matriz 1 de la forma: "<<endl;
		
		ejemplo = 0;
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				
				ejemplo = ejemplo+1;
				ejemplo1[i][j] = ejemplo;	
			}
		}
		
		ejemplo = 0;
		
		for(i=0;i<4;i++){
			for(j=0;j<2;j++){
				ejemplo = ejemplo+1;
				ejemplo2[i][j] = ejemplo;	
			}
		}
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cout<<"\t t"<<ejemplo1[i][j];
			}	
			cout<<endl;
		}
		
		cout<<"\nDonde t indica el numero de termino a ingresar"<<endl;
		
		for(i=0;i<4;i++){
			for(j=0;j<2;j++){
				cout<<"\t t"<<ejemplo2[i][j];
			}	
			cout<<endl;
		}
		
		cout<<"\nPor ejemplo t1 indica que es el primer termino que tiene que ingresar"<<endl;
			
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){			
				cin>>a;
				matriz1[i][j] = a;
			}
		}
			
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				cout<<"\t"<<matriz1[i][j];
			}	
			cout<<endl;
		}
			
		cout<<"Ingrese el tamaño de la matriz 2"<<endl;
		cout<<"Ingrese el numero de filas de la matriz 2: "; cin>>filas2;
		cout<<"Ingrese el numero de columnas de la matriz 2: "; cin>>columnas2;
			
		float matriz2[filas2][columnas2];
			
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){			
				matriz2[i][j] = 0;
			}
		}
			
		cout<<"\nIngrese los terminos de la matriz 2 de la forma: "<<endl;
		
		ejemplo = 0;
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				
				ejemplo = ejemplo+1;
				ejemplo1[i][j] = ejemplo;	
			}
		}
		
		ejemplo = 0;
		
		for(i=0;i<4;i++){
			for(j=0;j<2;j++){
				ejemplo = ejemplo+1;
				ejemplo2[i][j] = ejemplo;	
			}
		}
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cout<<"\t t"<<ejemplo1[i][j];
			}	
			cout<<endl;
		}
		
		cout<<"\nDonde t indica el numero de termino a ingresar"<<endl;
		
		for(i=0;i<4;i++){
			for(j=0;j<2;j++){
				cout<<"\t t"<<ejemplo2[i][j];
			}	
			cout<<endl;
		}
		
		cout<<"\nPor ejemplo t1 indica que es el primer termino que tiene que ingresar"<<endl;
			
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){				
				cin>>a;
				matriz2[i][j] = a;
			}
		}
			
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				cout<<"\t"<<matriz2[i][j];
			}	
			cout<<endl;
		}
		
		float matrizSuma[filas1][columnas1];
		float matrizResta[filas1][columnas1];
		float matrizMultiplicacion[filas1][columnas2];
		float matrizDivision[filas1][columnas2];
		
		float matrizInversa1[filas1][columnas1];
		
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				
				if(i==j){
					matrizInversa1[i][j] = 1;	
				}
				else
				{
					matrizInversa1[i][j] = 0;	
				}
			}
		}
		
		float matrizInversa2[filas2][columnas2];
		
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				
				if(i==j){
					matrizInversa2[i][j] = 1;	
				}
				else
				{
					matrizInversa2[i][j] = 0;	
				}
			}
		}
		
		float matrizParaDeterminante1[filas1][columnas1];
		
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizParaDeterminante1[i][j] = matriz1[i][j];
			}
		}
		
		float matrizParaDeterminante2[filas2][columnas2];
		
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizParaDeterminante2[i][j] = matriz2[i][j];
			}
		}
		
		float matriz1PorEscalar[filas1][columnas1];
		float matriz2PorEscalar[filas2][columnas2];
		float matrizTranspuesta1[columnas1][filas1];
		float matrizTranspuesta2[columnas2][filas2];		
		float matrizExponencial1[filas1][columnas1];
		float matrizExponencial2[filas2][columnas2];
		float matrizParaElevar1[filas1][columnas1];
		float matrizParaElevar2[filas2][columnas2];
		
		float matrizParaTriangular1[filas1][columnas1];
		
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizParaTriangular1[i][j] = matriz1[i][j];			
			}
		}
		
		float matrizParaTriangular2[filas2][columnas2];
		
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizParaTriangular2[i][j] = matriz2[i][j];			
			}
		}
		
		float matrizDiagonal1[filas1][columnas1];
		
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizDiagonal1[i][j] = 0;
			}
		}
		
		float matrizDiagonal2[filas2][columnas2];
		
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizDiagonal2[i][j] = 0;
			}
		}		
		
								
		float matrizL1[filas1][columnas1];
		float matrizU1[filas1][columnas1];
								
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizL1[i][j] = 0;
			}
		}
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizU1[i][j] = 0;
			}
		}
		
		float matrizL2[filas2][columnas2];
		float matrizU2[filas2][columnas2];
								
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizL2[i][j] = 0;
			}
		}
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizU2[i][j] = 0;
			}
		}
		
		float matrizTI1[filas1][columnas1];
		float matrizTS1[filas1][columnas1];
	
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizTI1[i][j] = 0;
			}
		}
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizTS1[i][j] = 0;
			}
		}
		
		float matrizTI2[filas2][columnas2];
		float matrizTS2[filas2][columnas2];
	
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizTI2[i][j] = 0;
			}
		}
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizTS2[i][j] = 0;
			}
		}
		
		float matrizParaInversa1[filas1][columnas1];
		
		for(i=0;i<filas1;i++){
			for(j=0;j<columnas1;j++){
				matrizParaInversa1[i][j] = matriz1[i][j];			
			}
		}
		
		float matrizParaInversa2[filas2][columnas2];
		
		for(i=0;i<filas2;i++){
			for(j=0;j<columnas2;j++){
				matrizParaInversa2[i][j] = matriz2[i][j];			
			}
		}	
		
		do{
			opciones();
			cin>>opcion;
			
			pivote = 0;
			pivote1 = 0;
			aux = 0;
			
			/*for(i=0;i<filas1;i++){
				for(j=0;j<columnas1;j++){
					cout<<"\t"<<matriz1[i][j];
				}	
				cout<<endl;
			} */
			
			switch(opcion){
				
				case 1:
					cout<<"La matriz suma es: "<<endl;
			
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){
							matrizSuma[i][j] = 0;
						}
					}
			
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){
							matrizSuma[i][j] = matriz1[i][j] + matriz2[i][j];
						}
					}
			
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){
							cout<<"\t"<<matrizSuma[i][j];
						}	
						cout<<endl;
					}
					break;
				
				case 2:
					cout<<"La matriz Resta es: "<<endl;	
				
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){
							matrizResta[i][j] = 0;
						}
					}
					
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){		
							matrizResta[i][j] = matriz1[i][j] - matriz2[i][j];
						}
					}
					
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas1;j++){
							cout<<"\t"<<matrizResta[i][j];
						}	
						cout<<endl;
					}
					break;
					
				case 3:
					cout<<"La matriz multiplicacion es: "<<endl;
		
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas2;j++){
							b = 0;
							for(k=0;k<filas2;k++){
								b = b + matriz1[i][k]*matriz2[k][j];
							}
							matrizMultiplicacion[i][j] = b;
						}
					}
						
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas2;j++){
							cout<<"\t"<<matrizMultiplicacion[i][j];
						}	
						cout<<endl;
					}
					break;
				
				case 4:
					cout<<"La matriz division es: "<<endl;
					
					for (i=0; i<filas2; i++){
								
						pivote = matriz2[i][i];	
								
						for (k=0; k<filas2; k++){
							matriz2[i][k]=matriz2[i][k]/pivote;
							matrizInversa2[i][k]=matrizInversa2[i][k]/pivote;
						}
									
						for (j=0; j<filas2; j++){
							if (i!=j){
								aux=matriz2[j][i];
										
								for (k=0; k<filas2; k++){
									matriz2[j][k]=matriz2[j][k]-aux*matriz2[i][k];
									matrizInversa2[j][k]=matrizInversa2[j][k]-aux*matrizInversa2[i][k];
								}
							}
						}
					}
					
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas2;j++){
							b = 0;
							for(k=0;k<filas2;k++){
								b = b + matriz1[i][k]*matrizInversa2[k][j];
							}
							matrizDivision[i][j] = b;
						}
					}
						
					for(i=0;i<filas1;i++){
						for(j=0;j<columnas2;j++){
							cout<<"\t"<<matrizDivision[i][j];
						}	
						cout<<endl;
					}
					break;
				
				case 5:
					
					do{	
						n = 1;
						
						elegirLaMatriz();
						cin>>nMatriz;
						
						det=1;
						
						switch(nMatriz){
							
							case 1:
								cout<<"El determinante de la matriz 1 es: "<<endl;
								
								for(i=0; i<filas1; i++){
									pivote = matrizParaDeterminante1[i][i];
									
									for(j=i+1; j<filas1; j++){
										pivote1 = matrizParaDeterminante1[j][i];
										aux = pivote1/pivote;
										for(k=0; k<filas1; k++){
											matrizParaDeterminante1[j][k]=matrizParaDeterminante1[j][k]-aux*matrizParaDeterminante1[i][k];
										}	  
									}
								}

								for (i=0; i<filas1; i++){
								    det*=matrizParaDeterminante1[i][i];									
								}	
								
								cout<<det;							
								break;
								
							case 2:
								cout<<"El determinante de la matriz 2 es: "<<endl;
								
								for(i=0; i<filas2; i++){
									pivote = matrizParaDeterminante2[i][i];
									
									for(j=i+1; j<filas2; j++){
										pivote1 = matrizParaDeterminante2[j][i];
										aux = pivote1/pivote;
										for(k=0; k<filas2; k++){
											matrizParaDeterminante2[j][k]=matrizParaDeterminante2[j][k]-aux*matrizParaDeterminante2[i][k];
										}	  
									}
								}
								
								for (i=0; i<filas2; i++){
								    det*=matrizParaDeterminante2[i][i];									
								}	
								
								cout<<det;
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);  
					break;
					
				case 6:
					
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								cout<<"La inversa de la matriz 1 es: "<<endl;
								
								for (i=0; i<filas1; i++){
									
									pivote = matrizParaInversa1[i][i];	
									for (k=0; k<filas1; k++)
									{
										matrizParaInversa1[i][k]=matrizParaInversa1[i][k]/pivote;
										matrizInversa1[i][k]=matrizInversa1[i][k]/pivote;
									}
									
									for (j=0; j<filas1; j++)
									{
										if (i!=j)   
										{
											aux=matrizParaInversa1[j][i];
										
											for (k=0; k<filas1; k++)
											{
												matrizParaInversa1[j][k]=matrizParaInversa1[j][k]-aux*matrizParaInversa1[i][k];
												matrizInversa1[j][k]=matrizInversa1[j][k]-aux*matrizInversa1[i][k];
											}
										}
									}
								}
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matrizInversa1[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 2:
								cout<<"La inversa de la matriz 2 es: "<<endl;
								
								for (i=0; i<filas2; i++){
									
									pivote = matrizParaInversa2[i][i];	
								
									for (k=0; k<filas2; k++)
									{
										matrizParaInversa2[i][k]=matrizParaInversa2[i][k]/pivote;
										matrizInversa2[i][k]=matrizInversa2[i][k]/pivote;
									}
									
									for (j=0; j<filas2; j++)
									{
										if (i!=j)   
										{
											aux=matrizParaInversa2[j][i];
										
											for (k=0; k<filas2; k++)
											{
												matrizParaInversa2[j][k]=matrizParaInversa2[j][k]-aux*matrizParaInversa2[i][k];
												matrizInversa2[j][k]=matrizInversa2[j][k]-aux*matrizInversa2[i][k];
											}
										}
									}
								}
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matrizInversa2[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 7:
									
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								cout<<"La transpuesta de la matriz 1 es: "<<endl;
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										matrizTranspuesta1[j][i] = matriz1 [i][j];
									}
								}
								
								for(i=0;i<columnas1;i++){
									for(j=0;j<filas1;j++){
										cout<<"\t"<<matrizTranspuesta1[i][j];
									}	
									cout<<endl;
								}								
								break;
								
							case 2:
								cout<<"La transpuesta de la matriz 2 es: "<<endl;
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										matrizTranspuesta2[j][i] = matriz2[i][j];
									}
								}
								for(i=0;i<columnas2;i++){
									for(j=0;j<filas2;j++){
										cout<<"\t"<<matrizTranspuesta2[i][j];
									}	
									cout<<endl;
								}																								
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 8:

					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								cout<<"El rango de la matriz 1 es: "<<endl;
								
								for(i=0; i<filas1; i++){
									pivote = matrizParaTriangular1[i][i];
									for(j=i+1;j<columnas1;j++){
										pivote1=matrizParaTriangular1[j][i];
										aux=pivote1/pivote;
										for (k=0;k<columnas1;k++){
											matrizParaTriangular1[j][k] = matrizParaTriangular1[j][k]-aux*matrizParaTriangular1[i][k];
										}	  
									}
								}
								
								comprobar = 0;
								comprobar1 = 0;
								
								for(i=0;i<columnas1;i++){
									comprobar = 0;
									for(j=0;j<columnas1;j++){
										comprobar = comprobar+matrizParaTriangular1[i][j];
									}
									if(comprobar==0){
										comprobar1 = comprobar1 + 1;
									}
								}
								
								cout<<filas1-comprobar1<<endl;
					
								break;
								
							case 2:
								cout<<"El rango de la matriz 2 es: "<<endl;
								
								for(i=0; i<filas2; i++){
									pivote = matrizParaTriangular2[i][i];
									for(j=i+1;j<columnas2;j++){
										pivote1=matrizParaTriangular2[j][i];
										aux=pivote1/pivote;
										for (k=0;k<columnas2;k++){
											matrizParaTriangular2[j][k] = matrizParaTriangular2[j][k]-aux*matrizParaTriangular2[i][k];
										}	  
									}
								}
								
								comprobar = 0;
								comprobar1 = 0;
								
								for(i=0;i<columnas2;i++){
									comprobar = 0;
									for(j=0;j<columnas2;j++){
										comprobar = comprobar+matrizParaTriangular2[i][j];
									}
									if(comprobar==0){
										comprobar1 = comprobar1 + 1;
									}
								}
								
								cout<<filas2-comprobar1<<endl;
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 9:
	
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								
								cout<<"Escriba el numero por el que quiere multiplicar la matriz 1: "; cin>>escalar;
								cout<<"El resultado de la multiplicacion es: "<<endl;
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										
										matriz1PorEscalar[i][j]=escalar*matriz1[i][j];
									}
								}
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matriz1PorEscalar[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 2:
								
								cout<<"Escriba el numero por el que quiere multiplicar la matriz 2: "; cin>>escalar;
								cout<<"El resultado de la multiplicacion es: "<<endl;
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										
										matriz2PorEscalar[i][j]=escalar*matriz2[i][j];
									}
								}
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matriz2PorEscalar[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 10:
					
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						pivote = 0;
						pivote1 = 0;
						aux = 0;
						
						switch(nMatriz){
							
							case 1:
								cout<<"La matriz triangular de la matriz 1 es: "<<endl;
								
								for(i=0; i<filas1; i++){
									pivote = matrizParaTriangular1[i][i];
									for(j=i+1;j<columnas1;j++){
										pivote1=matrizParaTriangular1[j][i];
										aux=pivote1/pivote;
										for (k=0;k<columnas1;k++){
											matrizParaTriangular1[j][k] = matrizParaTriangular1[j][k]-aux*matrizParaTriangular1[i][k];
										}	  
									}
								}
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matrizParaTriangular1[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 2:
								cout<<"La matriz triangular de la matriz 2 es: "<<endl;
								
								for(i=0; i<filas2; i++){
									pivote = matrizParaTriangular2[i][i];
									for(j=i+1;j<columnas2;j++){
										pivote1=matrizParaTriangular2[j][i];
										aux=pivote1/pivote;
										for (k=0;k<columnas2;k++){
											matrizParaTriangular2[j][k] = matrizParaTriangular2[j][k]-aux*matrizParaTriangular2[i][k];
										}	  
									}
								}
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matrizParaTriangular2[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 11:
	
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						paraDiagonal1 = 0;
						paraDiagonal2 = 0;
						paraDiagonal3 = 0;
						paraDiagonal4 = 0;
		
						switch(nMatriz){
							
							case 1:
								cout<<"La matriz diagonal de la matriz 1 es: "<<endl;
								
								if(filas1==2 and columnas1==2){
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]);
									paraDiagonal3 = (matriz1[0][0]*matriz1[1][1])-(matriz1[0][1]*matriz1[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
									
									matrizDiagonal1[0][0] = autovalor1;
									matrizDiagonal1[1][1] = autovalor2;
									
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizDiagonal1[i][j];
										}	
										cout<<endl;
									}	
								}
								
								else{
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]+matriz1[2][2]);
									paraDiagonal3 = (matriz1[0][0]*(matriz1[1][1]+matriz1[2][2]))+(matriz1[1][1]*matriz1[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz1[0][1]*matriz1[1][0])-(matriz1[2][1]*matriz1[1][2])-(matriz1[0][2]*matriz1[2][0]);
									paraDiagonal4 = (matriz1[1][0]*((matriz1[0][1]*matriz1[2][2])-(matriz1[0][2]*matriz1[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][2]*((matriz1[0][0]*matriz1[2][1])-(matriz1[0][1]*matriz1[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][1]*((matriz1[0][2]*matriz1[2][0])-(matriz1[0][0]*matriz1[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									matrizDiagonal1[0][0] = autovalor1;
									matrizDiagonal1[1][1] = autovalor2;		
									matrizDiagonal1[2][2] = autovalor3;		
									
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizDiagonal1[i][j];
										}	
										cout<<endl;
									}					
								}
								break;
								
							case 2:
								cout<<"La matriz diagonal de la matriz 2 es: "<<endl;
								
								if(filas2==2 and columnas2==2){
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]);
									paraDiagonal3 = (matriz2[0][0]*matriz2[1][1])-(matriz2[0][1]*matriz2[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
									
									matrizDiagonal2[0][0] = autovalor1;
									matrizDiagonal2[1][1] = autovalor2;
									
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizDiagonal2[i][j];
										}	
										cout<<endl;
									}	
								}
								
								else{
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]+matriz2[2][2]);
									paraDiagonal3 = (matriz2[0][0]*(matriz2[1][1]+matriz2[2][2]))+(matriz2[1][1]*matriz2[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz2[0][1]*matriz2[1][0])-(matriz2[2][1]*matriz2[1][2])-(matriz2[0][2]*matriz2[2][0]);
									paraDiagonal4 = (matriz2[1][0]*((matriz2[0][1]*matriz2[2][2])-(matriz2[0][2]*matriz2[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][2]*((matriz2[0][0]*matriz2[2][1])-(matriz2[0][1]*matriz2[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][1]*((matriz2[0][2]*matriz2[2][0])-(matriz2[0][0]*matriz2[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									matrizDiagonal2[0][0] = autovalor1;
									matrizDiagonal2[1][1] = autovalor2;		
									matrizDiagonal2[2][2] = autovalor3;		
									
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizDiagonal2[i][j];
										}	
										cout<<endl;
									}					
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 12:
					
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								
								cout<<"Ingrese el valor del exponente al que quiere elevar la matriz 1: "; cin>>exponente;
								cout<<"El resultado de elevar la matriz 1 es: "<<endl;
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										matrizParaElevar1[i][j] = matriz1[i][j];
									}
								}
													
								for(h=0;h<exponente-1;h++){
									for(i=0;i<filas1;i++){	
										for(j=0;j<columnas1;j++){
											b = 0;
											for(k=0;k<filas1;k++){
												b = b + matrizParaElevar1[i][k]*matriz1[k][j];
											}
											matrizExponencial1[i][j] = b;
										}
									}
									
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											matrizParaElevar1[i][j] = matrizExponencial1[i][j];
										}
									}
								}
								
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matrizExponencial1[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 2:
								cout<<"Ingrese el valor del exponente al que quiere elevar la matriz 2: "; cin>>exponente;
								cout<<"El resultado de elevar la matriz 2 es: "<<endl;
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										matrizParaElevar2[i][j] = matriz2[i][j];
									}
								}
													
								for(h=0;h<exponente-1;h++){
									for(i=0;i<filas2;i++){	
										for(j=0;j<columnas2;j++){
											b = 0;
											for(k=0;k<filas2;k++){
												b = b + matrizParaElevar2[i][k]*matriz2[k][j];
											}
											matrizExponencial2[i][j] = b;
										}
									}
									
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											matrizParaElevar2[i][j] = matrizExponencial2[i][j];
										}
									}
								}
								
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matrizExponencial2[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 13:
	
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						switch(nMatriz){
							
							case 1:
								cout<<"Factorizando la matriz 1 obtenemos: "<<endl;
								
								for(j=0;j<filas1;j++){
									matrizU1[0][j]=matriz1[0][j];
								} 
								for(i=1;i<filas1;i++){
									matrizL1[i][0]=matriz1[i][0]/matrizU1[0][0];
								}
								for (i = 0; i <filas1; i ++){
									matrizL1[i][i] = 1;
								}
								
								for(i=1;i<filas1;i++){
									for(j=i;j<columnas1;j++)
									{
										sum=0;
										for(k=0;k<=i-1;k++){
											sum+=matrizL1[i][k]*matrizU1[k][j];
										}
										matrizU1[i][j]=matriz1[i][j]-sum;
										sum=0;
										for(k=0;k<=i-1;k++){
											sum+=matrizL1[j][k]*matrizU1[k][i];
										}	
										matrizL1[j][i]=(matriz1[j][i]-sum)/matrizU1[i][i];
									}
								}
								
								cout<<"matriz 1: "<<endl;	
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matriz1[i][j];
									}	
									cout<<endl;
								}
								
								cout<<"matriz L: "<<endl;	
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matrizL1[i][j];
									}	
									cout<<endl;
								}	
								
								cout<<"matriz U: "<<endl;	
								for(i=0;i<filas1;i++){
									for(j=0;j<columnas1;j++){
										cout<<"\t"<<matrizU1[i][j];
									}	
									cout<<endl;
								}								
								break;
								
							case 2:
								cout<<"Factorizando la matriz 2 obtenemos: "<<endl;
								
								for(j=0;j<filas2;j++){
									matrizU2[0][j]=matriz2[0][j];
								} 
								for(i=1;i<filas2;i++){
									matrizL2[i][0]=matriz2[i][0]/matrizU2[0][0];
								}
								for (i = 0; i <filas2; i ++){
									matrizL2[i][i] = 1;
								}
								
								for(i=1;i<filas2;i++){
									for(j=i;j<columnas2;j++)
									{
										sum=0;
										for(k=0;k<=i-1;k++){
											sum+=matrizL2[i][k]*matrizU2[k][j];
										}
										matrizU2[i][j]=matriz2[i][j]-sum;
										sum=0;
										for(k=0;k<=i-1;k++){
											sum+=matrizL2[j][k]*matrizU2[k][i];
										}	
										matrizL2[j][i]=(matriz2[j][i]-sum)/matrizU2[i][i];
									}
								}
								
								cout<<"matriz 2: "<<endl;	
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matriz2[i][j];
									}	
									cout<<endl;
								}
								
								cout<<"matriz L: "<<endl;	
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matrizL2[i][j];
									}	
									cout<<endl;
								}	
								
								cout<<"matriz U: "<<endl;	
								for(i=0;i<filas2;i++){
									for(j=0;j<columnas2;j++){
										cout<<"\t"<<matrizU2[i][j];
									}	
									cout<<endl;
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 14:
	
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						termino1 = 0;
						termino2 = 0;
						termino3 = 0;
						termino4 = 0;
						termino5 = 0;
						termino6 = 0;
						
						switch(nMatriz){
							
							case 1:
								cout<<"Factorizando la matriz 1 obtenemos: "<<endl;
								
								if(filas1==2 and columnas1==2){
									termino1 = sqrt(matriz1[0][0]);
									termino2 = matriz1[0][1]/termino1;
									termino3 = sqrt(matriz1[1][1]-(pow(termino2,2)));
									
									matrizTI1[0][0] = termino1;
									matrizTI1[1][0] = termino2;
									matrizTI1[1][1] = termino3;
									
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											matrizTS1[i][j] = matrizTI1[j][i];
										}
									}
									
									cout<<"matriz 1: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matriz1[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangulas INFERIOR: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizTI1[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangular SUPERIOR: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizTS1[i][j];
										}	
										cout<<endl;
									}									
								}
								else{
									termino1 = sqrt(matriz1[0][0]);
									termino2 = matriz1[0][1]/termino1;
									termino3 = sqrt(matriz1[1][1]-(pow(termino2,2)));
									termino4 = matriz1[2][0]/termino1;
									termino5 = (matriz1[2][1]-(termino2*termino4))/termino3;
									termino6 = sqrt(matriz1[2][2]-pow(termino4,2)-pow(termino5,2));
									
									matrizTI1[0][0] = termino1;
									matrizTI1[1][0] = termino2;
									matrizTI1[1][1] = termino3;
									matrizTI1[2][0] = termino4;
									matrizTI1[2][1] = termino5;
									matrizTI1[2][2] = termino6;
									
									for(i=0;i<filas1;i++){
										for(j=0;j<filas1;j++){
											matrizTS1[i][j] = matrizTI1[j][i];
										}
									}
									
									cout<<"matriz 1: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matriz1[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangulas INFERIOR: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizTI1[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangular SUPERIOR: "<<endl;	
									for(i=0;i<filas1;i++){
										for(j=0;j<columnas1;j++){
											cout<<"\t"<<matrizTS1[i][j];
										}	
										cout<<endl;
									}
								}
								break;
								
							case 2:
								cout<<"Factorizando la matriz 2 obtenemos: "<<endl;
								
								if(filas2==2 and columnas2==2){
									termino1 = sqrt(matriz2[0][0]);
									termino2 = matriz2[0][1]/termino1;
									termino3 = sqrt(matriz2[1][1]-(pow(termino2,2)));
									
									matrizTI2[0][0] = termino1;
									matrizTI2[1][0] = termino2;
									matrizTI2[1][1] = termino3;
									
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											matrizTS2[i][j] = matrizTI2[j][i];
										}
									}
									
									cout<<"matriz 2: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matriz2[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangular INFERIOR: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizTI2[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangular SUPERIOR: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizTS2[i][j];
										}	
										cout<<endl;
									}									
								}
								else{
									termino1 = sqrt(matriz2[0][0]);
									termino2 = matriz2[0][1]/termino1;
									termino3 = sqrt(matriz2[1][1]-(pow(termino2,2)));
									termino4 = matriz2[2][0]/termino1;
									termino5 = (matriz2[2][1]-(termino2*termino4))/termino3;
									termino6 = sqrt(matriz2[2][2]-pow(termino4,2)-pow(termino5,2));
									
									matrizTI2[0][0] = termino1;
									matrizTI2[1][0] = termino2;
									matrizTI2[1][1] = termino3;
									matrizTI2[2][0] = termino4;
									matrizTI2[2][1] = termino5;
									matrizTI2[2][2] = termino6;
									
									for(i=0;i<filas2;i++){
										for(j=0;j<filas2;j++){
											matrizTS2[i][j] = matrizTI2[j][i];
										}
									}
									
									cout<<"matriz 2: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matriz2[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangulas INFERIOR: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizTI2[i][j];
										}	
										cout<<endl;
									}
									cout<<"matriz triangular SUPERIOR: "<<endl;	
									for(i=0;i<filas2;i++){
										for(j=0;j<columnas2;j++){
											cout<<"\t"<<matrizTS2[i][j];
										}	
										cout<<endl;
									}
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 15:
			
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						paraDiagonal1 = 0;
						paraDiagonal2 = 0;
						paraDiagonal3 = 0;
						paraDiagonal4 = 0;
						
						switch(nMatriz){
							
							case 1:
								cout<<"Los valores propios de la matriz 1 son: "<<endl;
					
								if(filas1==2 and columnas1==2){
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]);
									paraDiagonal3 = (matriz1[0][0]*matriz1[1][1])-(matriz1[0][1]*matriz1[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
									
									cout<<"El primer valor propio es: "<<autovalor1<<endl;
									cout<<"El segundo valor propio es: "<<autovalor2<<endl;
								}
								
								else{
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]+matriz1[2][2]);
									paraDiagonal3 = (matriz1[0][0]*(matriz1[1][1]+matriz1[2][2]))+(matriz1[1][1]*matriz1[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz1[0][1]*matriz1[1][0])-(matriz1[2][1]*matriz1[1][2])-(matriz1[0][2]*matriz1[2][0]);
									paraDiagonal4 = (matriz1[1][0]*((matriz1[0][1]*matriz1[2][2])-(matriz1[0][2]*matriz1[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][2]*((matriz1[0][0]*matriz1[2][1])-(matriz1[0][1]*matriz1[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][1]*((matriz1[0][2]*matriz1[2][0])-(matriz1[0][0]*matriz1[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									cout<<"\nEl primer valor propio es: "<<autovalor1<<endl;
									cout<<"El segundo valor propio es: "<<autovalor2<<endl;	
									cout<<"El tercer valor propio es: "<<autovalor3<<endl;				
								}
								break;
								
							case 2:
								cout<<"Los valores propios de la matriz 2 son: "<<endl;
								
								if(filas2==2 and columnas2==2){
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]);
									paraDiagonal3 = (matriz2[0][0]*matriz2[1][1])-(matriz2[0][1]*matriz2[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
									
									cout<<"El primer valor propio es: "<<autovalor1<<endl;
									cout<<"El segundo valor propio es: "<<autovalor2<<endl;
								}
								
								else{
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]+matriz2[2][2]);
									paraDiagonal3 = (matriz2[0][0]*(matriz2[1][1]+matriz2[2][2]))+(matriz2[1][1]*matriz2[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz2[0][1]*matriz2[1][0])-(matriz2[2][1]*matriz2[1][2])-(matriz2[0][2]*matriz2[2][0]);
									paraDiagonal4 = (matriz2[1][0]*((matriz2[0][1]*matriz2[2][2])-(matriz2[0][2]*matriz2[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][2]*((matriz2[0][0]*matriz2[2][1])-(matriz2[0][1]*matriz2[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][1]*((matriz2[0][2]*matriz2[2][0])-(matriz2[0][0]*matriz2[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									cout<<"\nEl primer valor propio es: "<<autovalor1<<endl;
									cout<<"El segundo valor propio es: "<<autovalor2<<endl;	
									cout<<"El tercer valor propio es: "<<autovalor3<<endl;					
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
					
				case 16:
				
					do{	
						n = 1;
						elegirLaMatriz();
						cin>>nMatriz;
						
						paraDiagonal1 = 0;
						paraDiagonal2 = 0;
						paraDiagonal3 = 0;
						paraDiagonal4 = 0;
						
						autovector1 = 0;
						autovector2 = 0;
						autovector3 = 0;
						autovector4 = 0;
						autovector5 = 0;
						autovector6 = 0;
						autovector7 = 0;
						autovector8 = 0;
						autovector9 = 0;
						
						switch(nMatriz){
							
							case 1:
								cout<<"Los vectores propios de la matriz 1 son: "<<endl;
								
								if(filas1==2 and columnas1==2){
									
									float vectorPropio1a [filas1];
									float vectorPropio1b [filas1];
		
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]);
									paraDiagonal3 = (matriz1[0][0]*matriz1[1][1])-(matriz1[0][1]*matriz1[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
							
									autovector1 = matriz1[0][1];
									autovector2 = autovalor1-matriz1[0][0];
									autovector3 = matriz1[0][1];
									autovector4 = autovalor2-matriz1[0][0];
									
									vectorPropio1a[0] = autovector1;
									vectorPropio1a[1] = autovector2;
									vectorPropio1b[0] = autovector3;
									vectorPropio1b[1] = autovector4;
									
									cout<<"Vector Propio 1:\t"<<vectorPropio1a<<endl;
									cout<<"Vector Propio 2:\t"<<vectorPropio1b<<endl;
								}
								
								else{
									float vectorPropio1a[filas1];
									float vectorPropio1b[filas1];
									float vectorPropio1c[filas1];
									
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz1[0][0]+matriz1[1][1]+matriz1[2][2]);
									paraDiagonal3 = (matriz1[0][0]*(matriz1[1][1]+matriz1[2][2]))+(matriz1[1][1]*matriz1[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz1[0][1]*matriz1[1][0])-(matriz1[2][1]*matriz1[1][2])-(matriz1[0][2]*matriz1[2][0]);
									paraDiagonal4 = (matriz1[1][0]*((matriz1[0][1]*matriz1[2][2])-(matriz1[0][2]*matriz1[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][2]*((matriz1[0][0]*matriz1[2][1])-(matriz1[0][1]*matriz1[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz1[1][1]*((matriz1[0][2]*matriz1[2][0])-(matriz1[0][0]*matriz1[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									autovector1 = (matriz1[0][1]*matriz1[1][2])+matriz1[0][2]*(autovalor1-matriz1[1][1]);
									autovector2 = (matriz1[0][2]*matriz1[1][0])+matriz1[1][2]*(autovalor1-matriz1[0][0]);
									autovector3 = ((autovalor1-matriz1[1][1])*(autovalor1-matriz1[0][0]))-(matriz1[0][1]*matriz1[1][0]);
									autovector4 = (matriz1[0][1]*matriz1[1][2])+matriz1[0][2]*(autovalor2-matriz1[1][1]);
									autovector5 = (matriz1[0][2]*matriz1[1][0])+matriz1[1][2]*(autovalor2-matriz1[0][0]);
									autovector6 = ((autovalor2-matriz1[1][1])*(autovalor2-matriz1[0][0]))-(matriz1[0][1]*matriz1[1][0]);
									autovector7 = (matriz1[0][1]*matriz1[1][2])+matriz1[0][2]*(autovalor3-matriz1[1][1]);
									autovector8 = (matriz1[0][2]*matriz1[1][0])+matriz1[1][2]*(autovalor3-matriz1[0][0]);
									autovector9 = ((autovalor3-matriz1[1][1])*(autovalor3-matriz1[0][0]))-(matriz1[0][1]*matriz1[1][0]);
									
									vectorPropio1a[0] = autovector1;
									vectorPropio1a[1] = autovector2;
									vectorPropio1a[2] = autovector3;
									vectorPropio1b[0] = autovector4;
									vectorPropio1b[1] = autovector5;
									vectorPropio1b[2] = autovector6;
									vectorPropio1c[0] = autovector7;
									vectorPropio1c[1] = autovector8;
									vectorPropio1c[2] = autovector9;
									
									cout<<"Vector Propio 1:\t"<<vectorPropio1a<<endl;
									cout<<"Vector Propio 2:\t"<<vectorPropio1b<<endl;	
									cout<<"Vector Propio 3:\t"<<vectorPropio1c<<endl;							
								}
								break;
								
							case 2:
								cout<<"Los vectores propios de la matriz 2 son: "<<endl;
								
								if(filas1==2 and columnas1==2){
										
									float vectorPropio2a [filas2];
									float vectorPropio2b [filas2];
		
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]);
									paraDiagonal3 = (matriz2[0][0]*matriz2[1][1])-(matriz2[0][1]*matriz2[1][0]);
									
									resolverEcuacion2Grado(paraDiagonal1, paraDiagonal2, paraDiagonal3, autovalor1, autovalor2);
								
									autovector1 = matriz2[0][1];
									autovector2 = autovalor1-matriz2[0][0];
									autovector3 = matriz2[0][1];
									autovector4 = autovalor2-matriz2[0][0];
									
									vectorPropio2a[0] = autovector1;
									vectorPropio2a[1] = autovector2;
									vectorPropio2b[0] = autovector3;
									vectorPropio2b[1] = autovector4;
									
									cout<<"Vector Propio 1:\t"<<vectorPropio2a<<endl;
									cout<<"Vector Propio 2:\t"<<vectorPropio2b<<endl;
								}
								
								else{
									float vectorPropio2a[filas1];
									float vectorPropio2b[filas1];
									float vectorPropio2c[filas1];
									
									paraDiagonal1 = 1;
									paraDiagonal2 = -1*(matriz2[0][0]+matriz2[1][1]+matriz2[2][2]);
									paraDiagonal3 = (matriz2[0][0]*(matriz2[1][1]+matriz2[2][2]))+(matriz2[1][1]*matriz2[2][2]);
									paraDiagonal3 = paraDiagonal3-(matriz2[0][1]*matriz2[1][0])-(matriz2[2][1]*matriz2[1][2])-(matriz2[0][2]*matriz2[2][0]);
									paraDiagonal4 = (matriz2[1][0]*((matriz2[0][1]*matriz2[2][2])-(matriz2[0][2]*matriz2[2][1])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][2]*((matriz2[0][0]*matriz2[2][1])-(matriz2[0][1]*matriz2[2][0])));
									paraDiagonal4 = paraDiagonal4+(matriz2[1][1]*((matriz2[0][2]*matriz2[2][0])-(matriz2[0][0]*matriz2[2][2])));
									
									resolverEcuacion3Grado(paraDiagonal1,paraDiagonal2,paraDiagonal3,paraDiagonal4,autovalor1,autovalor2,autovalor3);
									
									autovector1 = (matriz2[0][1]*matriz2[1][2])+matriz2[0][2]*(autovalor1-matriz2[1][1]);
									autovector2 = (matriz2[0][2]*matriz2[1][0])+matriz2[1][2]*(autovalor1-matriz2[0][0]);
									autovector3 = ((autovalor1-matriz2[1][1])*(autovalor1-matriz2[0][0]))-(matriz2[0][1]*matriz2[1][0]);
									autovector4 = (matriz2[0][1]*matriz2[1][2])+matriz2[0][2]*(autovalor2-matriz2[1][1]);
									autovector5 = (matriz2[0][2]*matriz2[1][0])+matriz2[1][2]*(autovalor2-matriz2[0][0]);
									autovector6 = ((autovalor2-matriz2[1][1])*(autovalor2-matriz2[0][0]))-(matriz2[0][1]*matriz2[1][0]);
									autovector7 = (matriz2[0][1]*matriz2[1][2])+matriz2[0][2]*(autovalor3-matriz2[1][1]);
									autovector8 = (matriz2[0][2]*matriz2[1][0])+matriz2[1][2]*(autovalor3-matriz2[0][0]);
									autovector9 = ((autovalor3-matriz2[1][1])*(autovalor3-matriz2[0][0]))-(matriz2[0][1]*matriz2[1][0]);
									
									vectorPropio2a[0] = autovector1;
									vectorPropio2a[1] = autovector2;
									vectorPropio2a[2] = autovector3;
									vectorPropio2b[0] = autovector4;
									vectorPropio2b[1] = autovector5;
									vectorPropio2b[2] = autovector6;
									vectorPropio2c[0] = autovector7;
									vectorPropio2c[1] = autovector8;
									vectorPropio2c[2] = autovector9;
									
									cout<<"Vector Propio 1:\t"<<vectorPropio2a<<endl;
									cout<<"Vector Propio 2:\t"<<vectorPropio2b<<endl;	
									cout<<"Vector Propio 3:\t"<<vectorPropio2c<<endl;							
								}
								break;
								
							case 3:
								n = n + 1;
								break;		
						}
					}while(n==1);
					break;
				
				case 17:
					m = m+1;
					break;
					
				case 18:
					m = m+1;
					reescribir = 2;
					break;		
			}
		}while(m==1);			
	}while(reescribir==0);
	return 0;	
}
