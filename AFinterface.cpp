#pragma HLS INTERFACE s_axilite port = b
#pragma HLS INTERFACE s_axilite port = c
#pragma HLS INTERFACE s_axilite port = d
#pragma HLS INTERFACE s_axilite port = e
#pragma HLS INTERFACE s_axilite port = f
#pragma HLS INTERFACE s_axilite port = g
#pragma HLS INTERFACE s_axilite port = m
#pragma HLS INTERFACE s_axilite port = n
#pragma HLS INTERFACE s_axilite port = j
#pragma HLS INTERFACE s_axilite port = k
	int A[7];
  //the ... is the parameters in neural network,the user could train their own model or ask our lab for more detail
	int Hw[7][10] = ...;
	int Hb[10] = ...;
	int Hw2[10][10] = ...;
	int Hb2[10] = ...;
	int Hw3[10][10] =   ...;
	int Hb3[10] =  ...;
	int Hw4[10][10] =  ...;
	int Hb4[10] = ...;
	int Ow[10][2] = ...;
	int Ob[2] = ...;

	A[0] = a;
	A[1] = b;
	A[2] = c;
	A[3] = d;
	A[4] = e;
	A[5] = f;
	A[6] = g;
	int B[10],C[10],D[10],E[10],F[2];

	interface_label1:for (int i = 0; i < 10; i++) {
		B[i] = 0;
		interface_label0:for (int j = 0; j < 7; j++) {
			B[i]= B[i] + A[j] * Hw[j][i]/1024;
		}
		B[i] = B[i] + Hb[i] ;
		if(B[i]<0) B[i]=0;
	}

	interface_label3:for (int i = 0; i < 10; i++) {
		C[i] = 0;
		interface_label2:for (int j = 0; j < 10; j++) {
			C[i]= C[i] + B[j] * Hw2[j][i]/1024;
		}
		C[i] = C[i] + Hb2[i] ;
		if(C[i]<0) C[i]=0;
	}

	interface_label5:for (int i = 0; i < 10; i++) {
		D[i] = 0;
		interface_label4:for (int j = 0; j < 10; j++) {
			D[i]= D[i] + C[j] * Hw3[j][i]/1024;
		}
		D[i] = D[i] + Hb3[i] ;
		if(D[i]<0) D[i]=0;
	}

	interface_label7:for (int i = 0; i < 10; i++) {
		E[i] = 0;
		interface_label6:for (int j = 0; j < 10; j++) {
			E[i]= E[i] + D[j] * Hw4[j][i]/1024;
		}
		E[i] = E[i] + Hb4[i] ;
		if(E[i]<0) E[i]=0;
	}

	interface_label9:for (int i = 0; i < 2; i++) {
		F[i] = 0;
		interface_label8:for (int j = 0; j < 10; j++) {
			F[i] = F[i] + E[j] * Ow[j][i]/1024;
		}
		F[i] = F[i] + Ob[i] ;
	}
	m = 2;
	if (F[0] > F[1])
		{m = 0 ;}
	else
	{m = 1;}


}
