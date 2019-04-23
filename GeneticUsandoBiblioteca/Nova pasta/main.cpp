#include <string>
#include <iostream>
#include <fstream>
#include "openga.hpp"

using std::string;
using std::cout;
using std::endl;

int SourceX, SourceY, DestinationX, DestinationY;

struct Path
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;

	string to_string() const
	{
		return
			string("{")
			+  "x1:"+std::to_string(x1)
			+", y1:"+std::to_string(y1)
			+", x2:"+std::to_string(x2)
			+", y2:"+std::to_string(y2)
			+", x3:"+std::to_string(x3)
			+", y3:"+std::to_string(y3)
			+"}";
	}
};

struct IntermediateCost
{
	// This is where the results of simulation
	// is stored but not yet finalized.
	double objective1;
	double objective2;
	double objective3;
	double objective4;
};

typedef EA::Genetic<Path,IntermediateCost> GA_Type;
typedef EA::GenerationType<Path,IntermediateCost> Generation_Type;

void init_genes(Path& p,const std::function<double(void)> &rnd01)
{
	// rnd01() gives a random number in 0~1
	p.x1=0.0+10*rnd01();
	p.y1=0.0+10*rnd01();
	p.x2=0.0+10*rnd01();
	p.y2=0.0+10*rnd01();
	p.x3=0.0+10*rnd01();
	p.y3=0.0+10*rnd01();
}

bool eval_solution(
	const Path& p,
	IntermediateCost &c)
{
	const int& x1=p.x1;
	const int& y1=p.y1;
	const int& x2=p.x2;
	const int& y2=p.y2;
	const int& x3=p.x3;
	const int& y3=p.y3;

	c.objective1=sqrt((x1-SourceX)*(x1-SourceX)+(y1-SourceY)*(y1-SourceY));
	c.objective2=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	c.objective3=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	c.objective4=sqrt((DestinationX-x3)*(DestinationX-x3)+(DestinationY-y3)*(DestinationY-y3));
	return true; // solution is accepted
}

Path mutate(
	const Path& X_base,
	const std::function<double(void)> &rnd01,
	double shrink_scale)
{
	Path X_new;
	bool in_range;
	do{
		in_range=true;
		X_new=X_base;
		X_new.x1+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.x1>=0.0 && X_new.x1<10.0);
		X_new.y1+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.y1>=0.0 && X_new.y1<10.0);
		X_new.x2+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.x2>=0.0 && X_new.x2<10.0);
		X_new.y2+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.y2>=0.0 && X_new.y2<10.0);
		X_new.x3+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.x3>=0.0 && X_new.x3<10.0);
		X_new.y3+=0.2*(rnd01()-rnd01())*shrink_scale;
		in_range=in_range&&(X_new.y3>=0.0 && X_new.y3<10.0);
	} while(!in_range);
	return X_new;
}

Path crossover(
	const Path& X1,
	const Path& X2,
	const std::function<double(void)> &rnd01)
{
	Path X_new;
	double r;
	r=rnd01();
	X_new.x1=r*X1.x1+(1.0-r)*X2.x1;
	r=rnd01();
	X_new.y1=r*X1.y1+(1.0-r)*X2.y1;
	r=rnd01();
	X_new.x2=r*X1.x2+(1.0-r)*X2.x2;
	r=rnd01();
	X_new.y2=r*X1.y2+(1.0-r)*X2.y2;
	r=rnd01();
	X_new.x3=r*X1.x3+(1.0-r)*X2.x3;
	r=rnd01();
	X_new.y3=r*X1.y3+(1.0-r)*X2.y3;
	return X_new;
}

double calculate_SO_total_fitness(const GA_Type::thisChromosomeType &X)
{
	// finalize the cost
	double final_cost=0.0;
	final_cost+=X.middle_costs.objective1;
	final_cost+=X.middle_costs.objective2;
	final_cost+=X.middle_costs.objective3;
	final_cost+=X.middle_costs.objective4;
	return final_cost;
}

std::ofstream output_file;

void SO_report_generation(
	int generation_number,
	const EA::GenerationType<Path,IntermediateCost> &last_generation,
	const Path& best_genes)
{
	cout
		<<"Generation ["<<generation_number<<"], "
		<<"Best="<<last_generation.best_total_cost<<", "
		<<"Average="<<last_generation.average_cost<<", "
		<<"Best genes=("<<best_genes.to_string()<<")"<<", "
		<<"Exe_time="<<last_generation.exe_time
		<<endl;

	output_file
		<<generation_number<<"\t"
		<<last_generation.average_cost<<"\t"
		<<last_generation.best_total_cost<<"\t"
		<<best_genes.to_string()<<"\n";
}

int main()
{
    SourceX = 2;
    SourceY = 2;
    DestinationX = 9;
    DestinationY = 9;
	output_file.open("results.txt");
	output_file<<"step"<<"\t"<<"cost_avg"<<"\t"<<"cost_best"<<"\t"<<"solution_best"<<"\n";

	EA::Chronometer timer;
	timer.tic();

	GA_Type ga_obj;
	ga_obj.problem_mode=EA::GA_MODE::SOGA;
	ga_obj.multi_threading=false;
	ga_obj.verbose=false;
	ga_obj.population=200;
	ga_obj.generation_max=1000;
	ga_obj.calculate_SO_total_fitness=calculate_SO_total_fitness;
	ga_obj.init_genes=init_genes;
	ga_obj.eval_solution=eval_solution;
	ga_obj.mutate=mutate;
	ga_obj.crossover=crossover;
	ga_obj.SO_report_generation=SO_report_generation;
	ga_obj.best_stall_max=10;
	ga_obj.elite_count=10;
	ga_obj.crossover_fraction=0.7;
	ga_obj.mutation_rate=0.2;
	ga_obj.best_stall_max=10;
	ga_obj.elite_count=10;
	ga_obj.solve();



	cout<<"The problem is optimized in "<<timer.toc()<<" seconds."<<endl;

	output_file.close();
	return 0;
}
