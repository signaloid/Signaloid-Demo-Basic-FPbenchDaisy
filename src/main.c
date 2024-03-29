/*
 *	Authored 2021, Orestis Kaparounakis.
 *
 *	All rights reserved.
 *
 *	Redistribution and use in source and binary forms, with or without
 *	modification, are permitted provided that the following conditions
 *	are met:
 *	*	Redistributions of source code must retain the above
 *		copyright notice, this list of conditions and the following
 *		disclaimer.
 *	*	Redistributions in binary form must reproduce the above
 *		copyright notice, this list of conditions and the following
 *		disclaimer in the documentation and/or other materials
 *		provided with the distribution.
 *	*	Neither the name of the author nor the names of its
 *		contributors may be used to endorse or promote products
 *		derived from this software without specific prior written
 *		permission.
 *
 *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *	POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uxhw.h>

#include "daisy.h"

enum {
	kBenchmarkFunctionCount 	= 7, 
	kBenchmarkMaxArgumentCount 	= 9,
};

double	loadDoubleDistFromPath(double *  var, const char * folder, const char *  filename);
void	usage();

int
main(int argc, char *  argv[])
{
	char *  folder = "test";
	double	ex[kBenchmarkFunctionCount];
	double	in[kBenchmarkFunctionCount][kBenchmarkMaxArgumentCount];

	if (argc == 1)
	{
	}
	else if (argc == 2)
	{
		folder = argv[1];
	}
	else
	{
		usage();
		exit(EXIT_FAILURE);
	}

	/*
	 *	Load samples into distributional double variables and call
	 *	benchmark functions.
	 */
	loadDoubleDistFromPath(&in[0][0], folder, "input-ex0-x.txt");
	loadDoubleDistFromPath(&in[0][1], folder, "input-ex0-y.txt");
	ex[0] = ex0(in[0][0], in[0][1]);
	printf("ex0 = %lf\n", ex[0]);

	loadDoubleDistFromPath(&in[1][0], folder, "input-ex1-x.txt");
	loadDoubleDistFromPath(&in[1][1], folder, "input-ex1-y.txt");
	ex[1] = ex1(in[1][0], in[1][1]);
	printf("ex1 = %lf\n", ex[1]);

	loadDoubleDistFromPath(&in[2][0], folder, "input-ex2-radius.txt");
	loadDoubleDistFromPath(&in[2][1], folder, "input-ex2-theta.txt");
	ex[2] = ex2(in[2][0], in[2][1]);
	printf("ex2 = %lf\n", ex[2]);

	loadDoubleDistFromPath(&in[3][0], folder, "input-ex3-radius.txt");
	loadDoubleDistFromPath(&in[3][1], folder, "input-ex3-theta.txt");
	ex[3] = ex3(in[3][0], in[3][1]);
	printf("ex3 = %lf\n", ex[3]);

	loadDoubleDistFromPath(&in[4][0], folder, "input-ex4-t.txt");
	loadDoubleDistFromPath(&in[4][1], folder, "input-ex4-resistance.txt");
	loadDoubleDistFromPath(&in[4][2], folder, "input-ex4-frequency.txt");
	loadDoubleDistFromPath(&in[4][3], folder, "input-ex4-inductance.txt");
	loadDoubleDistFromPath(&in[4][4], folder, "input-ex4-maxVoltage.txt");
	ex[4] = ex4(in[4][0], in[4][1], in[4][2], in[4][3], in[4][4]);
	printf("ex4 = %lf\n", ex[4]);

	loadDoubleDistFromPath(&in[5][0], folder, "input-ex5-a.txt");
	loadDoubleDistFromPath(&in[5][1], folder, "input-ex5-b.txt");
	loadDoubleDistFromPath(&in[5][2], folder, "input-ex5-c.txt");
	loadDoubleDistFromPath(&in[5][3], folder, "input-ex5-d.txt");
	loadDoubleDistFromPath(&in[5][4], folder, "input-ex5-e.txt");
	loadDoubleDistFromPath(&in[5][5], folder, "input-ex5-f.txt");
	loadDoubleDistFromPath(&in[5][6], folder, "input-ex5-g.txt");
	loadDoubleDistFromPath(&in[5][7], folder, "input-ex5-h.txt");
	loadDoubleDistFromPath(&in[5][8], folder, "input-ex5-i.txt");
	ex[5] = ex5(in[5][0], in[5][1], in[5][2], in[5][3], in[5][4], in[5][5], in[5][6], in[5][7], in[5][8]);
	printf("ex5 = %lf\n", ex[5]);

	loadDoubleDistFromPath(&in[6][0], folder, "input-ex6-a.txt");
	loadDoubleDistFromPath(&in[6][1], folder, "input-ex6-b.txt");
	loadDoubleDistFromPath(&in[6][2], folder, "input-ex6-c.txt");
	loadDoubleDistFromPath(&in[6][3], folder, "input-ex6-d.txt");
	loadDoubleDistFromPath(&in[6][4], folder, "input-ex6-e.txt");
	loadDoubleDistFromPath(&in[6][5], folder, "input-ex6-f.txt");
	loadDoubleDistFromPath(&in[6][6], folder, "input-ex6-g.txt");
	loadDoubleDistFromPath(&in[6][7], folder, "input-ex6-h.txt");
	loadDoubleDistFromPath(&in[6][8], folder, "input-ex6-i.txt");
	ex[6] = ex6(in[6][0], in[6][1], in[6][2], in[6][3], in[6][4], in[6][5], in[6][6], in[6][7], in[6][8]);
	printf("ex6 = %lf\n", ex[6]);

	return 0;
}

double
loadDoubleDistFromPath(double *  var, const char * folder, const char *  filename)
{
	const char * pathTemplate = "%s/%s";
	char *       pathFilled;
	size_t       needed = 0;

	FILE *		inp;
	int		sampleCount;
	double *	samples;
	double		returnValue;

	needed = snprintf(NULL, 0, pathTemplate, folder, filename) + 1;
	pathFilled = malloc(needed);
	if (pathFilled == NULL)
	{
		fprintf(stderr, "Error: could not allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	snprintf(pathFilled, needed, pathTemplate, folder, filename);

	inp = fopen(pathFilled, "r");
	if (inp == NULL)
	{
		fprintf(stderr, "Error: could not open input file: %s\n", pathFilled);
		exit(EXIT_FAILURE);
	}

	if (fscanf(inp, "%d\n", &sampleCount) != 1)
	{
		fprintf(stderr, "Error: could not read number of samples at start of input file.\n");
		free(pathFilled);
		exit(EXIT_FAILURE);
	}

	printf("Number of samples from %s: %d\n", pathFilled, sampleCount);

	samples = calloc(sampleCount, sizeof(double));
	if (samples == NULL)
	{
		fprintf(stderr, "Error: could not allocate memory for samples.\n");
		free(pathFilled);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < sampleCount; i++)
	{
		fscanf(inp, "%lf\n", &samples[i]);
	}

	if (var == NULL )
	{
		returnValue = UxHwDoubleDistFromSamples(samples, sampleCount);
	}
	else
	{
		(*var) = UxHwDoubleDistFromSamples(samples, sampleCount);
	}

	if (fclose(inp) != 0)
	{
		fprintf(stderr, "Warning: could not close input file.\n");
	}
	free(pathFilled);
	free(samples);

	return returnValue;
}

void
usage(void)
{
	fprintf(stderr, "Usage: <folder> (optional)\n");
}
