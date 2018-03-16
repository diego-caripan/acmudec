/*************************************************************************************************************************
 * Uva 902 - Password Search
 * http://uva.onlinejudge.org/external/9/p902.pdf
 *
 * Classification: 
 *
 * Author: Jury
 *
 * Date: 29-08-2014
 *
 * Descripcion:
 * 
**/
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

int main()
{
	int N;
	while( scanf("%d", &N) != EOF )
	{
		std::string str;
		std::cin >> str;
		std::map<std::string, int> map;
		for( int i = 0; i < str.size()-N; ++i )
		{
			map[ str.substr(i, N) ]++;
		}

		std::map<std::string, int>::iterator it;
		int max = 0;
		std::string sol;
		for( it = map.begin(); it != map.end(); ++it )
		{
			if( it->second > max )
			{
				max = it->second;
				sol = it->first;
			}
		}
		std::cout << sol << std::endl;
	}
	return 0;
}
