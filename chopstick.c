// Andrew Bossie
// Chopstick Optmimization
// Example of Linear Regression using BGD for fining the optimal chopstick length

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include <gsl_matrix_float.h>
//#include <gsl_blas.h>

int main(int argc, char* argv[]){

	int i, j;
	float trainingSet[186][2];
	float XTrain[165];
	float yTrain[165];
	float XTest[20];
	float yTest[20];
	float gradient = 0.0; 
	float theta = 0.0; 
	float X = 0.0; //input vector
	float y = 0.0; //output

	float h = theta + theta * i; //hypothesis function
	
//READ
	char buf[255];
	char *line, *read;
	FILE fstream = fopen("./chopstickTrain.csv", "r"); //Hard-coded
	while((line = fgets(buf, sizeof(buf), fstream)) != NULL){
		read = strok(line, ",");
		while(read != NULL){
			trainingSet[i][j++] = atof(read);
			read = strok(NULL, ",");
		}
		++i;
	}

//PREPROCESS

	//Shuffle
	printf("Shuffling data...\n");

	for(i = 0; i < 165; i++){
		r = rand();
		trainingSet[i][0] = trainingSet[r][0];
	}

	//Split
	printf("Splitting datasets into train and test...\n");

	for(i=0; i < 165; i++){
		for(j=0; i < 2; j++){
			Xtrain[i] = trainingSet[i][0];
			yTrain[i] = trainingSet[i][1];
		}
	}

	for(i=0; i < 21; i++){
		for(j=0; i < 2; j++){
			Xtrain[i] = trainingSet[i][0];
			yTrain[i] = trainingSet[i][1];
		}
	}

	printf("Centering at 0 and normalizing...\n");
	//mean center

	//normalize

//TRAIN

	float eta = 0.01;
	printf("Training dataset...\n");

	//Calculate Gradient (Batch)
	for(i = 0; i < Xtrain[i]; i++){

		gradient = (1/2(Xtrain.lenghth()))(XTrain[i] - yTrain[i])(XTrain[i]);
		theta += theta - eta * gradient;
	}

	printf("Optimal theta value found: %ld\n\n\n", theta);

//TEST

	//To do: K-folds
	//Print % error
	for(i=0, i < 21; i++){
		float error = h / ytest[i][0];
		printf("Value: %ld\tError: %ld\n", h, error);
	}
}