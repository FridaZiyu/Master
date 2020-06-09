#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <iterator>
#include <iomanip>
#include <limits>
#include <functional>
//using namespace std;

int main(){
	double f[] = {1.1, 1.2, 1.2, 1.5, 0.4, 0.1, -4.3, 0.1, -1.3};
	std::vector<double> v(0);
	unsigned int len = sizeof(f) / sizeof(f[0]);
	//1) copy
	v.resize(len);
	std::copy(f,f+len,v.begin());
	std::cout<<"origin: ";
	std::copy(v.cbegin(),v.cend(),std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	//2) Sort f ascending
	std::sort(f, f+len);
	//3) median 
	int n = len/2;
	if (len%2==1)
		std::cout<<"median: "<< f[n] << '\n';
	else
		std::cout<<"median: "<< (f[n-1]+f[n])/2.0 << '\n';

	//4) mean
	double sum = std::accumulate(v.cbegin(),v.cend(),(double)0.0);
	if (std::fabs(sum) <= std::numeric_limits<double>::epsilon())
		sum = 0;
	double mean=sum/len;
	std::cout<<"mean: "<< mean << '\n';
	//5) standard deviation
	double var = std::accumulate(v.cbegin(),v.cend(),(double)0.0,[mean](double a,double d){
		return a + std::pow(d - mean,2);});		
	std::cout<<"standard deviation: "<< std::sqrt(var) << '\n';
	
	//6) insert unique_copy 
	std::unique_copy(f,f+len, std::back_inserter(v));
	
	//7) print v
	std::copy(v.cbegin(),v.cend(),std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	//8) print c descending
	std::vector<double> temp(v);
	std::sort(temp.begin(),temp.end(), std::greater<double>());
	std::copy(temp.cbegin(),temp.cend(),std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	std::copy(v.rbegin(),v.rend(),std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	//9) recover 
	std::copy(v.begin(),v.begin()+len,f);
	
	//10) print original sequence
	std::copy(f,f+len,std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	//11) replace all negative numbers with 9.9
	std::replace_if (f, f+len, [](double i){return (i<0);}, 9.9);
	std::copy(f,f+len,std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	//12) the difference of neighbor elements
	std::vector<double> diff(len);
	std::adjacent_difference(f,f+len,diff.begin());
	std::cout<<"slope: ";
	std::copy(diff.begin(),diff.end(),std::ostream_iterator<double>(std::cout,","));
	std::cout<<std::endl;
	
	//13) count negative, positive and zero slope
	int negative = std::count_if(diff.cbegin(), diff.cend(), [](double i){return i < 0;});
	int zero = std::count(diff.cbegin(), diff.cend(),0.0);
	int positive = std::count_if(diff.cbegin(), diff.cend(), [](double i){return i > 0;});
	std::cout<< "count: negative: " << negative << " ,positive: " << positive << " ,zero: " << zero << '\n';
	
	//14) find the largest slope
	
	auto max_slope = std::max_element(diff.cbegin(), diff.cend());
	//auto max_slope = *std::max_element(diff.cbegin(), diff.cend());
	auto max_abs_slope = std::max_element(diff.cbegin(), diff.cend(), [](double a, double b){return (std::fabs(a) < std::fabs(b));});
	
	std::cout<< " the largest slope is at " <<std::distance(diff.cbegin(),max_slope) << ", value is " << *max_slope << '\n';
	if (max_slope != max_abs_slope)
		std::cout<< "or at " <<std::distance(diff.cbegin(),max_abs_slope) << ", value is " << *max_abs_slope << '\n';
	
	return 0;
}