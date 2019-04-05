#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
 
using namespace std;
 
typedef vector< vector< char > > twod_vector;
 
ostream& operator<<(ostream &out, const twod_vector &v)
{
	twod_vector::const_iterator p;
 
	for(p = v.begin(); p < v.end(); p++) {
		copy((*p).begin(), (*p).end(),
				ostream_iterator< char >(cout, ""));
		cout<<endl;
	}
 
	return out;
}
 
void reset(twod_vector &image)
{
	twod_vector::iterator p;
 
	for(p = image.begin(); p < image.end(); p++) {
		fill((*p).begin(), (*p).end(), 'O');
	}
}
 
void set_pixel(twod_vector &image, int x, int y, char c)
{
	image.at(y).at(x) = c;
}
 
void fill_rect(twod_vector &image,
		int x1, int y1, int x2, int y2, char c)
{
	for(int i = y1; i <= y2; i++) {
		for(int j = x1; j <= x2; j++) {
			image.at(i).at(j) = c;
		}
	}
}
 
void fill_region(twod_vector &image, int x, int y,
		char old_color, char new_color)
{
	if(old_color == new_color) {
		return;
	}
 
	image.at(y).at(x) = new_color;
 
	if(x > 0) {
		if(image.at(y).at(x - 1) == old_color) {
			fill_region(image, x - 1, y,
					old_color, new_color);
		}
	}
 
	if(x < static_cast<int>(image.at(y).size()) - 1) {
		if(image.at(y).at(x + 1) == old_color) {
			fill_region(image, x + 1, y,
					old_color, new_color);
		}
	}
 
	if(y > 0) {
		if(image.at(y - 1).at(x) == old_color) {
			fill_region(image, x, y - 1,
					old_color, new_color);
		}
	}
 
	if(y < static_cast<int>(image.size()) - 1) {
		if(image.at(y + 1).at(x) == old_color) {
			fill_region(image, x, y + 1,
					old_color, new_color);
		}
	}
}
 
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
 
int main(int argc, char *argv[])
{
	twod_vector image;
	string line;
 
	getline(cin, line);
	while(line[0] != 'X') {
		istringstream iss(line);
		int m, n, x, y, x1, x2, y1, y2;
		char command, c, file_name[13];
		twod_vector::iterator p;
 
		iss>>command;
		switch(command) {
		case 'I':
			iss>>m>>n;
 
			image.clear();
			image.resize(n);
			for(p = image.begin(); p < image.end(); p++) {
				(*p).resize(m);
			}
 
			reset(image);
 
			break;
		case 'C':
			reset(image);
 
			break;
		case 'L':
			iss>>x>>y>>c;
			x--;
			y--;
 
			set_pixel(image, x, y, c);
 
			break;
		case 'V':
			iss>>x>>y1>>y2>>c;
			x--;
			y1--;
			y2--;
 
			if(y1 > y2) {
				swap(y1, y2);
			}
 
			fill_rect(image, x, y1, x, y2, c);
 
			break;
		case 'H':
			iss>>x1>>x2>>y>>c;
			x1--;
			x2--;
			y--;
 
			if(x1 > x2) {
				swap(x1, x2);
			}
 
			fill_rect(image, x1, y, x2, y, c);
 
			break;
		case 'K':
			iss>>x1>>y1>>x2>>y2>>c;
			x1--;
			y1--;
			x2--;
			y2--;
 
			if(x1 > x2) {
				swap(x1, x2);
			}
			if(y1 > y2) {
				swap(y1, y2);
			}
 
			fill_rect(image, x1, y1, x2, y2, c);
 
			break;
		case 'F':
			iss>>x>>y>>c;
			x--;
			y--;
 
			fill_region(image, x, y,
					image.at(y).at(x), c);
 
			break;
		case 'S':
			iss.ignore();
			iss.getline(file_name, 13);
 
			cout<<file_name<<endl;
			cout<<image;
 
			break;
		}
 
		getline(cin, line);
	}
 
	return 0;
}