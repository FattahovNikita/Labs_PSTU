#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <string>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
using namespace sf;
vector<vector<int>> copyMatrix;
vector<vector<int>> grafMatrix;
vector<pair<int, int>> list_for_paths;
vector<int>copyVertexList;
Font font;
int WinW = 1350;
int WinH = 730;
template<class T>
class Graph
{
private:
	int maxSize;
	queue<T> VertsQueue;
public:
	vector<vector<int>> matrix;
	vector<T> vertexList;
	Graph() : Graph(20) {}
	Graph(const int& size) {
		maxSize = size;
		matrix = vector<vector<T>>(size, vector<T>(size));
		for (int i = 0; i < maxSize; ++i) {
			for (int j = 0; j < maxSize; ++j)
				matrix[i][j] = 0;
		}
	}
	vector<T> GetList() {
		return vertexList;
	}
	bool isFull() {
		return vertexList.size() == maxSize;
	}
	bool isEmpty() {
		return vertexList.size() == 0;
	}
	void ReadyaddVertex(const T& vertex) {
		if (isFull()) {
			cout << "Кол-во вершин превышает максимум." << endl;
			return;
		}
		vertexList.push_back(vertex);
		copyVertexList.push_back(vertex);
	}
	void addVertex(const T& vertex) {
		if (isFull()) {
			cout << "Кол-во вершин превышает максимум." << endl;
			return;
		}
		vertexList.push_back(vertex);
		copyVertexList.push_back(vertex);
		int vertPos1 = GetPos(vertex);
		for (int i = 0; i < vertexList.size(); ++i) {
			matrix[i][vertPos1] = 0;
			matrix[vertPos1][i] = 0;
		}
	}
	int GetPos(const T& v) {
		for (int i = 0; i < vertexList.size(); ++i) {
			if (vertexList[i] == v) {
				return i;
			}
		}
		return -1;
	}
	int GetAmount() {
		return vertexList.size();
	}
	int GetWeight(const T& vfirst, const T& vsecond) {
		if (isEmpty()) {
			return 0;
		}
		int Pos_vfirst = GetPos(vfirst);
		int Pos_vsecond = GetPos(vsecond);
		if (Pos_vfirst == -1 || Pos_vsecond == -1) {
			cout << "Нет узла в графе " << endl;
			return 0;
		}
		return matrix[Pos_vfirst][Pos_vsecond];
	}
	vector<T> GetAdjVert(const T& vertex) {
		vector<T> AdjVertList;
		int pos = GetPos(vertex);
		if (pos != -1) {
			for (int i = 0; i < vertexList.size(); ++i) {
				if (matrix[pos][i] != 0) {
					AdjVertList.push_back(vertexList[i]);
				}
			}
		}
		return AdjVertList;
	}
	//oriented or not
	void AddEdge(const T& vertex1, const T& vertex2, int weight) {
		if (GetPos(vertex1) != (-1) && GetPos(vertex2) != (-1)) {
			int vertPos1 = GetPos(vertex1);
			int vertPos2 = GetPos(vertex2);

			if (matrix[vertPos1][vertPos2] != 0 && matrix[vertPos2][vertPos1] != 0) {
				cout << "Ребро уже есть" << endl;
				return;
			}
			else {
				matrix[vertPos1][vertPos2] = weight;   //1 для ориентированного графа
				matrix[vertPos2][vertPos1] = weight; //1,2 для неориентированного графа

			}
		}
		else {
			cout << "Одной из вершин нет в графе" << endl;
			return;
		}

	}
	//oriented or not
	void DeleteEdge(const T& vertex1, const T& vertex2) {
		if (GetPos(vertex1) != (-1) && GetPos(vertex2) != (-1)) {
			int vertPos1 = GetPos(vertex1);
			int vertPos2 = GetPos(vertex2);

			if (matrix[vertPos1][vertPos2] != 0 && matrix[vertPos2][vertPos1] != 0) {
				matrix[vertPos1][vertPos2] = 0;   //1 для ориентированного графа
				matrix[vertPos2][vertPos1] = 0; //1,2 для неориентированного графа
				return;
			}

		}
		else {
			cout << "Одной из вершин нет в графе" << endl;
			return;
		}

	}
	//not oriented
	void DeleteVertex(const T& vertex1) {
		vector<T> AdjVert = GetAdjVert(vertex1);
		int vertPos1 = GetPos(vertex1);
		matrix.erase(matrix.begin() + vertPos1);
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i].erase(matrix[i].begin() + vertPos1);
		}
		auto it = remove(vertexList.begin(), vertexList.end(), vertex1);
		vertexList.erase(it, vertexList.end());
		auto tit = remove(copyVertexList.begin(), copyVertexList.end(), vertex1);
		copyVertexList.erase(tit, copyVertexList.end());


	}
	void PrintMatrix() {
		if (!isEmpty()) {
			cout << endl;
			cout << "Матрица смежности: " << endl;
			cout << "-  ";
			for (int i = 0; i < vertexList.size(); ++i) {
				cout << vertexList[i] << "  ";
			}
			cout << endl;
			for (int i = 0; i < vertexList.size(); ++i) {
				cout << vertexList[i] << " ";
				for (int j = 0; j < vertexList.size(); ++j) {
					cout << " " << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Граф пуст" << endl;
		}
	}
	//oriented or not
	int GetAmountEdges() {
		int amount = 0;
		if (!isEmpty()) {
			for (int i = 0; i < vertexList.size(); ++i) {
				for (int j = 0; j < vertexList.size(); ++j) {
					if (matrix[i][j] != 0) {
						amount++;
					}
				}
			}
		}
		//return amount;        //для ориентированного графа
		return amount / 2;  //для неориентированного графа
	}
	void DFS(T& start, bool* visited) {
		cout << "Вершина " << start << " пройдена" << endl;
		visited[GetPos(start)] = true;
		vector<T> AdjVert = GetAdjVert(start);
		for (int i = 0; i < AdjVert.size(); ++i) {
			if (!visited[GetPos(AdjVert[i])]) {
				DFS(AdjVert[i], visited);
			}
		}
	}
	void simplePathfindingAlgoritm(int vertex1)
	{
		int start = GetPos(vertex1);
		bool* Visited = new bool[vertexList.size()];
		unsigned* distances = new unsigned[vertexList.size()];
		unsigned minimalWeight, minimalIndex;

		for (unsigned i = 0; i < vertexList.size(); ++i)
		{
			Visited[i] = false;
			distances[i] = INT_MAX;
		}

		distances[start] = 0;

		do
		{
			minimalIndex = INT_MAX;
			minimalWeight = INT_MAX;

			for (unsigned i = 0; i < vertexList.size(); ++i)
			{
				if (!Visited[i] && distances[i] < minimalWeight)
				{
					minimalIndex = i;
					minimalWeight = distances[i];
				}
			}

			if (minimalIndex != INT_MAX)
			{
				for (unsigned i = 0; i < vertexList.size(); ++i)
				{
					if (matrix[minimalIndex][i])
					{
						unsigned temp = minimalWeight + matrix[minimalIndex][i];

						if (temp < distances[i])
							distances[i] = temp;
					}
				}

				Visited[minimalIndex] = true;
			}
		} while (minimalIndex < INT_MAX);

		for (unsigned i = 0; i < vertexList.size(); ++i)
		{
			if (distances[i] != INT_MAX)
			{
				cout << "Вес: " << start << " ~> " << i << " = " << setw(6) << left << distances[i] << "\t";

				unsigned end = i;
				unsigned weight = distances[end];
				string way = to_string(end) + " >~ ";

				while (end != start)
				{
					for (unsigned j = 0; j < vertexList.size(); ++j)
					{
						if (matrix[j][end])
						{
							int temp = weight - matrix[j][end];

							if (temp == distances[j])
							{
								end = j;
								weight = temp;
								way += to_string(j) + " >~ ";
							}
						}
					}
				}

				cout << "Путь: ";

				for (int j = way.length() - 5; j >= 0; --j)
					cout << way[j];

				cout << endl;
			}
			else
				cout << "Вес: " << start << " ~ " << i << " = " << "маршрут недоступен" << endl;
		}
		delete[] Visited;
		delete[] distances;
	}
};
void ExtraMatrix(vector<vector<int> > matrix) {
	int amount = matrix.size();
	copyMatrix.clear();
	grafMatrix.clear();
	vector<int> temp_vec;
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++)
			if (i == j)
				temp_vec.push_back(-1);
			else
				temp_vec.push_back(matrix[i][j]);
		copyMatrix.push_back(temp_vec);
		temp_vec.clear();
	}
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++)
			temp_vec.push_back(matrix[i][j]);
		grafMatrix.push_back(temp_vec);
		temp_vec.clear();
	}
}
void RowReduction()
{
	int amount = copyMatrix.size();
	int size = amount;
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < size; j++)
		{
			if (copyMatrix[i][j] < min && copyMatrix[i][j] != -1)
				min = copyMatrix[i][j];
		}

		if (min != INT_MAX && min != 0)
		{
			for (int j = 0; j < size; j++)
			{
				if (copyMatrix[i][j] > 0 && copyMatrix[i][j] != INT_MAX)
					copyMatrix[i][j] -= min;
			}
		}
	}
}
void ColumnReduction()
{
	int amount = copyMatrix.size();
	int size = amount;
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < size; j++)
		{
			if (copyMatrix[j][i] < min && copyMatrix[j][i] != -1)
				min = copyMatrix[j][i];
		}

		if (min != INT_MAX && min != 0)
		{
			for (int j = 0; j < size; j++)
			{
				if (copyMatrix[j][i] > 0 && copyMatrix[j][i] != INT_MAX)
					copyMatrix[j][i] -= min;
			}
		}
	}
}
int FindMinInLine(int h, int g)
{
	int amount = copyMatrix.size();
	int min = INT_MAX;
	for (int i = 0; i < amount; i++)
	{
		if (copyMatrix[h][i] < min && i != g && copyMatrix[h][i] != -1)
			min = copyMatrix[h][i];
	}
	return min;
}
int FindMinInCol(int h, int g)
{
	int amount = copyMatrix.size();
	int min = INT_MAX;
	for (int i = 0; i < amount; i++)
	{
		if (copyMatrix[i][g] < min && i != h && copyMatrix[i][g] != -1)
			min = copyMatrix[i][g];
	}
	return min;
}
pair<int, int> FindPaths()
{
	int amount = copyMatrix.size();
	int max = INT_MIN;
	int size = amount;
	vector<vector < int>> cop = copyMatrix;
	std::pair<int, int> way;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (copyMatrix[i][j] == 0)
			{
				int mark = FindMinInLine(i, j) + FindMinInCol(i, j);
				if (max < mark)
				{
					max = mark;
					way.first = i;
					way.second = j;
				}
			}
		}
	}
	
	if (copyMatrix[way.second][way.first] == 0)
		copyMatrix[way.second][way.first] = -1;

	
	for (int i = 0; i < size; i++)
	{
		copyMatrix[way.first][i] = -1;
		copyMatrix[i][way.second] = -1;
	}
	return way;
}
void BranchBoundMethod()
{
	int amount = copyMatrix.size();
	copyMatrix = grafMatrix;
	for (int i = 0; i < amount; i++)
		for (int j = 0; j < amount; j++)
		{
			if (i == j)
				copyMatrix[i][j] = -1;
			if (copyMatrix[i][j] <= 0)
				copyMatrix[i][j] = -1;
		}

	int ii = 0;
	while (ii != amount)
	{
		RowReduction();
		ColumnReduction();
		std::pair<int, int> tmp;
		tmp = FindPaths();
		if (tmp != std::pair<int, int>(0, 0))
			list_for_paths.push_back(tmp);
		ii++;
	}
}
void Print_road() {
	cout << "Лучший маршрут:\n";
	int begin = 0;
	for (int i = 0; i < list_for_paths.size(); i++) {
		for (int j = 0; j < list_for_paths.size(); j++) {
			if (list_for_paths[j].first == begin) {
				cout << list_for_paths[j].first + 1;
				cout << " ~> ";
				begin = list_for_paths[j].second;
				break;
			}
		}
	}
	bool lastElementPrinted = false;
	for (int j = 0; j < list_for_paths.size(); j++)
		if (list_for_paths[j].first == begin) {
			cout << list_for_paths[j].first + 1;
			lastElementPrinted = true;
			break;
		}
	if (!lastElementPrinted) {
		for (int j = 0; j < list_for_paths.size(); j++)
			if (list_for_paths[j].second == begin)
				cout << list_for_paths[j].second + 1;
	}
	bool hasRoad = false;
	for (int i = 0; i < list_for_paths.size(); i++)
		if (list_for_paths[i].second == 0) {
			hasRoad = true;
			break;
		}
	if (!hasRoad)
		cout << "\nЗадача не имеет решения\n";
	cout << endl;
}
void Print_paths(vector<vector<int> > matrix) {
	cout << "Пути из одной вершины в другую:" << endl;
	for (int i = 0; i < list_for_paths.size(); i++)
		cout << list_for_paths[i].first + 1 << " ~> " << list_for_paths[i].second + 1
		<< " = " << matrix[list_for_paths[i].first][list_for_paths[i].second] << endl;
}
void Sum_of_paths(vector<vector<int> > matrix) {
	int sum = 0;
	cout << "Длина маршрута:\n";
	for (int i = 0; i < list_for_paths.size(); i++)
		sum += matrix[list_for_paths[i].first][list_for_paths[i].second];
	cout << sum << endl;
}
class Node {
public:
	Text nodename;
	string strname;
	CircleShape circle;
	int x;
	int y;
	int rad;
	int xname;
	int yname;
	Node() {
		xname = x + rad;
		yname = y + rad;
	}
};
class Line {
public:
	Text name;
	string strname;
	vector<Vertex> linest;
	int x1;
	int y1;
	int x2;
	int y2;
	Line() {
		
	}
};
void SetCoord(int i, int amountVert, vector<Node>& cities, Graph<int> graph)
{
	Node city;
	int R_;

	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		city.rad = 5 * (WinH / 13) / amountVert;
		R_ = WinH / 2 - city.rad - 10;
	}
	else {
		city.rad = 5 * (WinW / 13) / amountVert;
		R_ = WinW / 2 - city.rad - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(amountVert);
	city.x = R_ * cos(theta) + y0 + R_;
	city.y = R_ * sin(theta) + x0 - R_ - city.rad;
	city.xname = city.x + city.rad;
	city.yname = city.y + city.rad;
	city.circle.setPosition(city.x, city.y);
	city.circle.setFillColor(Color(65, 105, 225));
	city.circle.setRadius(city.rad);
	city.circle.setOutlineThickness(4);
	city.circle.setOutlineColor(Color::Black);
	city.nodename.setFont(font);
	city.nodename.setCharacterSize(30);
	city.nodename.setStyle(Text::Bold);
	city.nodename.setFillColor(sf::Color::Black);
	city.nodename.setPosition(city.xname-7, city.yname-17);
	city.nodename.setString(to_string(graph.vertexList[i]));
	city.strname = (to_string(graph.vertexList[i]));
	cities.push_back(city);
}



int main()
{
	setlocale(LC_ALL, "Russian");
	font.loadFromFile("TimesNewRoman.ttf");

	vector<Line> connections;
	vector<Line> bestconnections;
	vector<Node> cities;

	Graph<int> graph;
	
	ContextSettings settings;
	settings.antialiasingLevel = 0;

	// создание кнопок
	const float W = 150;
	const float H = 40;
	const float fy = 130;
	const float ax = 100;
	const float ter = 70;

	RectangleShape back(Vector2f(W+102, fy+ter*6));
	back.move(ax-50, fy-50);
	back.setFillColor(Color(255, 222, 173));
	back.setOutlineThickness(10.f);
	back.setOutlineColor(Color(188, 143, 143));

	float AnswerW = W;
	float AnswerH = H;
	float Answerx = ax;
	float Answery = fy + ter*2;
	RectangleShape Answer(Vector2f(AnswerW, AnswerH));
	Answer.move(Answerx, Answery);
	Answer.setFillColor(Color(240, 248, 255));
	Answer.setOutlineThickness(2.f);
	Answer.setOutlineColor(Color(0, 0, 0));
	Text TextAnswer;
	TextAnswer.setFont(font);
	TextAnswer.setCharacterSize(30);
	TextAnswer.setFillColor(sf::Color::Black);
	TextAnswer.setPosition(Answerx+22, Answery);
	TextAnswer.setString("Solution");


	float DrawW = W;
	float DrawH = H;
	float Drawx = ax;
	float Drawy = fy + ter;
	RectangleShape Draw(Vector2f(DrawW, DrawH));
	Draw.move(Drawx, Drawy);
	Draw.setFillColor(Color(240, 248, 255));
	Draw.setOutlineThickness(2.f);
	Draw.setOutlineColor(Color(0, 0, 0));
	Text TextDraw;
	TextDraw.setFont(font);
	TextDraw.setCharacterSize(30);
	TextDraw.setFillColor(sf::Color::Black);
	TextDraw.setPosition(Drawx+5, Drawy);
	TextDraw.setString("Print matrix");

	float NewW = W;
	float NewH = H;
	float Newx = ax;
	float Newy = fy;
	RectangleShape New(Vector2f(NewW, NewH));
	New.move(Newx, Newy);
	New.setFillColor(Color(240, 248, 255));
	New.setOutlineThickness(2.f);
	New.setOutlineColor(Color(0, 0, 0));
	Text TextNew;
	TextNew.setFont(font);
	TextNew.setCharacterSize(30);
	TextNew.setFillColor(sf::Color::Black);
	TextNew.setPosition(Newx + 5, Newy);
	TextNew.setString("New matrix");

	float AddW = W;
	float AddH = H;
	float Addx = ax;
	float Addy = fy+ter*3;
	RectangleShape Add(Vector2f(AddW, AddH));
	Add.move(Addx, Addy);
	Add.setFillColor(Color(240, 248, 255));
	Add.setOutlineThickness(2.f);
	Add.setOutlineColor(Color(0, 0, 0));
	Text TextAdd;
	TextAdd.setFont(font);
	TextAdd.setCharacterSize(30);
	TextAdd.setFillColor(sf::Color::Black);
	TextAdd.setPosition(Addx + 7, Addy);
	TextAdd.setString("Add vertex");

	float DelW = W;
	float DelH = H;
	float Delx = ax;
	float Dely = fy+ter*4;
	RectangleShape Del(Vector2f(DelW, DelH));
	Del.move(Delx, Dely);
	Del.setFillColor(Color(240, 248, 255));
	Del.setOutlineThickness(2.f);
	Del.setOutlineColor(Color(0, 0, 0));
	Text TextDel;
	TextDel.setFont(font);
	TextDel.setCharacterSize(30);
	TextDel.setFillColor(sf::Color::Black);
	TextDel.setPosition(Delx + 12, Dely);
	TextDel.setString("Del vertex");

	float DelEdgeW = W;
	float DelEdgeH = H;
	float DelEdgex = ax;
	float DelEdgey = fy+ter*6;
	RectangleShape DelEdge(Vector2f(DelEdgeW, DelEdgeH));
	DelEdge.move(DelEdgex, DelEdgey);
	DelEdge.setFillColor(Color(240, 248, 255));
	DelEdge.setOutlineThickness(2.f);
	DelEdge.setOutlineColor(Color(0, 0, 0));
	Text TextDelEdge;
	TextDelEdge.setFont(font);
	TextDelEdge.setCharacterSize(30);
	TextDelEdge.setFillColor(sf::Color::Black);
	TextDelEdge.setPosition(DelEdgex + 20, DelEdgey);
	TextDelEdge.setString("Del edge");

	float AddEdgeW = W;
	float AddEdgeH = H;
	float AddEdgex = ax;
	float AddEdgey = fy+ter*5;

	RectangleShape AddEdge(Vector2f(AddEdgeW, AddEdgeH));
	AddEdge.move(AddEdgex, AddEdgey);
	AddEdge.setFillColor(Color(240, 248, 255));
	AddEdge.setOutlineThickness(2.f);
	AddEdge.setOutlineColor(Color(0, 0, 0));
	Text TextAddEdge;
	TextAddEdge.setFont(font);
	TextAddEdge.setCharacterSize(30);
	TextAddEdge.setFillColor(sf::Color::Black);
	TextAddEdge.setPosition(AddEdgex + 17, AddEdgey);
	TextAddEdge.setString("Add edge");

    RenderWindow MainWindow(VideoMode(WinW, WinH), "MainWindow", Style::Default, settings);
    while (MainWindow.isOpen()) {
        Event event;
        while (MainWindow.pollEvent(event)) {
			Vector2i position = Mouse::getPosition(MainWindow);
			int x = position.x;
			int y = position.y;
			if  (x > 0 && y > 0 && x >= Answerx && x <= Answerx + AnswerW && y >= Answery && y <= Answery + AnswerH) {
				Answer.setFillColor(Color(0, 250, 154));
			}
			else if(x > 0 && y > 0 && x >= Newx && x <= Newx + NewW && y >= Newy && y <= Newy + NewH) {
				New.setFillColor(Color(0, 250, 154));
			}
			else if (x > 0 && y > 0 && x >= Drawx && x <= Drawx + DrawW && y >= Drawy && y <= Drawy + DrawH) {
				Draw.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= Addx && x <= Addx + AddW && y >= Addy && y <= Addy + AddH) {
				Add.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= Delx && x <= Delx + DelW && y >= Dely && y <= Dely + DelH) {
				Del.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= DelEdgex && x <= DelEdgex + DelEdgeW && y >= DelEdgey && y <= DelEdgey + DelEdgeH) {
				DelEdge.setFillColor(Color(0, 250, 154));
			}
			else if (x > 0 && y > 0 && x >= AddEdgex && x <= AddEdgex + AddEdgeW && y >= AddEdgey && y <= AddEdgey + AddEdgeH) {
				AddEdge.setFillColor(Color(0, 250, 154));;
			}

			else {
				Answer.setFillColor(Color(240, 248, 255));
				New.setFillColor(Color(240, 248, 255));
				Draw.setFillColor(Color(240, 248, 255));
				Add.setFillColor(Color(240, 248, 255));
				Del.setFillColor(Color(240, 248, 255));
				DelEdge.setFillColor(Color(240, 248, 255));
				AddEdge.setFillColor(Color(240, 248, 255));
			}
			switch (event.type) {
			case Event::MouseButtonPressed:
				
				if (event.key.code == Mouse::Left)
				{
					Vector2i position = Mouse::getPosition(MainWindow);
					int x = position.x;
					int y = position.y;

					if (x > 0 && y > 0 && x >= Answerx && x <= Answerx + AnswerW && y >= Answery && y <= Answery + AnswerH) {

						vector<vector<int>> tcopyMatrix;
						vector<vector<int>> tgrafMatrix;
						vector<pair<int, int>> tlist_for_paths;
						ExtraMatrix(graph.matrix);
						BranchBoundMethod();
						Print_paths(graph.matrix);
						cout << endl;
						Print_road();
						Sum_of_paths(graph.matrix);
						for (int i = 0; i < list_for_paths.size(); i++) {

							Line connect;
							connect.x1 = cities[graph.GetPos(list_for_paths[i].first + 1)].xname;
							connect.y1 = cities[graph.GetPos(list_for_paths[i].first + 1)].yname;
							connect.x2 = cities[graph.GetPos(list_for_paths[i].second + 1)].xname;
							connect.y2 = cities[graph.GetPos(list_for_paths[i].second + 1)].yname;
							connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color(255, 69, 0)));
							connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color(255, 69, 0)));
							bestconnections.push_back(connect);

						}
						grafMatrix.clear();
						copyMatrix.clear();
						list_for_paths.clear();
						/*for (int i = 0; i < copyVertexList.size(); ++i) {
							cout << copyVertexList[i] <<" ";
						}*/
					}
					if (x > 0 && y > 0 && x >= Newx && x <= Newx + NewW && y >= Newy && y <= Newy + NewH) {
						vector<Line> tempconnections;
						vector<Line> tempbestconnections;
						vector<Node> tempcities;
						Graph<int> tempgraph;
						int amountVert, amountEdge, edgeWeight;
						int vertex, initialVertex, endVertex;
						int answer = 0;
						while (answer != 1 && answer != 2) {
							cout << "Использовать готовую матрицу? 1 - Да, 2 - Нет: "; cin >> answer;
						}
						if (answer == 2) {
							cout << "Введите кол-во вершин графа: "; cin >> amountVert;
							cout << "Введите кол-во ребер графа: "; cin >> amountEdge;
							for (int i = 0; i < amountVert; ++i) {
								tempgraph.addVertex(i + 1);
								cout << "Вершина " << i + 1 << " создана" << endl;
								SetCoord(i, amountVert, tempcities, tempgraph);
							}
							for (int i = 0; i < amountEdge; ++i) {
								cout << "Исходная вершина: "; cin >> initialVertex;
								cout << "Конечная вершина: "; cin >> endVertex;
								cout << "Вес ребра: "; cin >> edgeWeight;
								tempgraph.AddEdge(initialVertex, endVertex, edgeWeight);
								Line connect;
								connect.x1 = tempcities[tempgraph.GetPos(initialVertex)].xname;
								connect.y1 = tempcities[tempgraph.GetPos(initialVertex)].yname;
								connect.x2 = tempcities[tempgraph.GetPos(endVertex)].xname;
								connect.y2 = tempcities[tempgraph.GetPos(endVertex)].yname;
								connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
								connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
								connect.name.setFont(font);
								connect.name.setCharacterSize(25);
								connect.name.setFillColor(sf::Color::Black);
								connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0);
								connect.name.setString(to_string(edgeWeight));
								tempconnections.push_back(connect);
							}
							graph = tempgraph;
							connections = tempconnections;
							bestconnections = tempbestconnections;
							cities = tempcities;
						}
						if (answer == 1) {
							//graph.matrix = {
							//	//        1   2   3  4  5  6
							//	/*1*/	{ 0, 12, 18, 5, 0, 34},
							//	/*2*/	{ 12, 0, 16, 0, 53, 45 },
							//	/*3*/	{ 18, 16, 0, 3, 21, 0 },
							//	/*4*/	{ 5, 0, 3, 0, 0, 0 },
							//	/*5*/	{ 0, 53, 21, 0, 0, 0 },
							//	/*6*/	{ 34, 45, 0, 0, 0, 0 }
							//};
							//tempgraph.matrix = {
							//	//        1  2   3   4  5  
							//	/*1*/	{ 0, 10, 15, 5, 12},
							//	/*2*/	{ 10, 0, 5, 17, 40},
							//	/*3*/	{ 15, 5, 0, 5, 21},
							//	/*4*/	{ 5, 17, 5, 0, 30},
							//	/*5*/	{ 12, 40, 21, 30, 0},

							//};
							amountVert = 5;
							for (int i = 0; i < amountVert; ++i) {
								tempgraph.ReadyaddVertex(i + 1);
								SetCoord(i, amountVert, tempcities, tempgraph);

							}

							tempgraph.AddEdge(1, 2, 10);
							tempgraph.AddEdge(1, 3, 15);
							tempgraph.AddEdge(1, 4, 5);
							tempgraph.AddEdge(1, 5, 12);
							tempgraph.AddEdge(2, 3, 5);
							tempgraph.AddEdge(2, 4, 17);
							tempgraph.AddEdge(2, 5, 40);
							tempgraph.AddEdge(3, 4, 5);
							tempgraph.AddEdge(3, 5, 21);
							tempgraph.AddEdge(4, 5, 30);
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = tempgraph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = tempcities[i].xname;
										connect.y1 = tempcities[i].yname;
										connect.x2 = tempcities[j].xname;
										connect.y2 = tempcities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										tempconnections.push_back(connect);
									}
								}
							}
							graph = tempgraph;
							connections = tempconnections;
							bestconnections = tempbestconnections;
							cities = tempcities;
						}
					}
					if (x > 0 && y > 0 && x >= Drawx && x <= Drawx + DrawW && y >= Drawy && y <= Drawy + DrawH) {
						graph.PrintMatrix();
					}
					if (x > 0 && y > 0 && x >= Addx && x <= Addx + AddW && y >= Addy && y <= Addy + AddH) {

						vector<Line> tempconnections;
						vector<Line> tempbestconnections;
						vector<Node> tempcities;
						Graph<int> tempgraph = graph;
						tempbestconnections = bestconnections;
						tempconnections = connections;
						if (graph.vertexList.size() != 0)graph.addVertex(*max_element(graph.vertexList.begin(), graph.vertexList.end()) + 1);
						if (graph.vertexList.size() == 0)graph.addVertex(graph.vertexList.size() + 1);
						int amountVert = graph.vertexList.size();
						cout << "Вершина " << graph.vertexList.size() << " создана" << endl;
						cities.clear();
						connections.clear();
						bestconnections.clear();
						for (int i = 0; i < amountVert; ++i) {
							SetCoord(i, amountVert, cities, graph);
						}
						for (int i = 0; i < amountVert; i++)
						{
							for (int j = i + 1; j < amountVert; j++)
							{
								int a = graph.matrix[i][j];
								if (a != 0)
								{
									Line connect;
									connect.x1 = cities[i].xname;
									connect.y1 = cities[i].yname;
									connect.x2 = cities[j].xname;
									connect.y2 = cities[j].yname;
									connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
									connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
									connect.name.setFont(font);
									connect.name.setCharacterSize(25);
									connect.name.setFillColor(sf::Color::Black);
									connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
									connect.name.setString(to_string(a));
									connections.push_back(connect);
								}
							}
						}



					}
					if (x > 0 && y > 0 && x >= Delx && x <= Delx + DelW && y >= Dely && y <= Dely + DelH) {
						int delvert;
						if (graph.vertexList.empty()) {
							cout << "Вершин для удаления нет" << endl;
							break;
						}
						vector<Line> tempconnections;
						tempconnections = connections;
						connections.clear();
						cout << "Введите вершину, которую нужно удалить "; cin >> delvert;
						bool t1 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == delvert)
								t1 = true;
						}
						if (!t1) {
							cout << "В графе нет данной вершины " << endl;
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								SetCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
							break;
						}
						else {
							vector<int> xx;
							for (int i = 0; i < graph.vertexList.size(); ++i) {
								xx.push_back(graph.GetWeight(delvert, i));
							}
							int vertPos2 = graph.GetPos(delvert);
							for (auto i : tempconnections) {
								for (int j = 0; j < xx.size(); ++j) {
									if (i.strname == to_string(xx[j])) {

										tempconnections.erase(tempconnections.begin() + vertPos2);
										vertPos2 += 1;
									}
								}

							}
							for (int i = 0; i < graph.vertexList.size(); ++i) {
								graph.DeleteEdge(delvert, i);
							}
							int vertPos1 = graph.GetPos(delvert);
							graph.DeleteVertex(delvert);
							for (auto i : cities) {
								if (i.strname == to_string(delvert)) {

									cities.erase(cities.begin() + vertPos1);
									break;
								}
							}
							connections = tempconnections;
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								SetCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
						}
					}
					if (x > 0 && y > 0 && x >= DelEdgex && x <= DelEdgex + DelEdgeW && y >= DelEdgey && y <= DelEdgey + DelEdgeH) {
						if (graph.vertexList.empty()) {
							cout << "Ребер для удаления нет" << endl;
							break;
						}
						if (graph.GetAmountEdges() == 0) {
							cout << "Ребер для удаления нет" << endl;
							break;
						}
						int deledge1, deledge2;
						cout << "Введите первую вершину ребра для удаления "; cin >> deledge1;
						cout << endl;
						cout << "Введите вторую вершину ребра для удаления "; cin >> deledge2;
						bool t1 = false;
						bool t2 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == deledge1)
								t1 = true;
							if (graph.vertexList[i] == deledge2)
								t2 = true;
						}
						if (!t1 || !t2) {
							cout << "В графе нет данного ребра" << endl;
							break;
						}
						else {
							graph.DeleteEdge(deledge1, deledge2);
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								SetCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
						}

					}
					if (x > 0 && y > 0 && x >= AddEdgex && x <= AddEdgex + AddEdgeW && y >= AddEdgey && y <= AddEdgey + AddEdgeH) {
						if (graph.vertexList.empty()) {
							cout << "Вершин для добавления ребер нет" << endl;
							break;
						}
						
						
						int initialVertex, endVertex, edgeWeight;
						cout << "Исходная вершина: "; cin >> initialVertex;
						cout << "Конечная вершина: "; cin >> endVertex;
						cout << "Вес ребра: "; cin >> edgeWeight;
						bool t1 = false;
						bool t2 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == initialVertex)
								t1 = true;
							if (graph.vertexList[i] == endVertex)
								t2 = true;
						}
						if (!t1 || !t2) {
							cout << "В графе нет данной вершины " << endl;
							break;
						}
						else {

							graph.AddEdge(initialVertex, endVertex, edgeWeight);
							Line connect;
							connect.x1 = cities[graph.GetPos(initialVertex)].xname;
							connect.y1 = cities[graph.GetPos(initialVertex)].yname;
							connect.x2 = cities[graph.GetPos(endVertex)].xname;
							connect.y2 = cities[graph.GetPos(endVertex)].yname;
							connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
							connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
							connect.name.setFont(font);
							connect.name.setCharacterSize(25);
							connect.name.setFillColor(sf::Color::Black);
							connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0);
							connect.name.setString(to_string(edgeWeight));
							connections.push_back(connect);
						}
						/*graph = tempgraph;
						connections = tempconnections;
						bestconnections = tempbestconnections;
						cities = tempcities;*/
					}



					break;
				}
				else break;


            case Event::Closed:
                MainWindow.close();
                break;

            }
        }
        MainWindow.clear(Color (135, 206, 250));
		MainWindow.draw(back);
		MainWindow.draw(Answer);
		MainWindow.draw(TextAnswer);
		MainWindow.draw(Draw);
		MainWindow.draw(TextDraw);
		MainWindow.draw(New);
		MainWindow.draw(TextNew);
		MainWindow.draw(Add);
		MainWindow.draw(TextAdd);
		MainWindow.draw(Del);
		MainWindow.draw(TextDel);
		MainWindow.draw(DelEdge);
		MainWindow.draw(TextDelEdge);
		MainWindow.draw(AddEdge);
		MainWindow.draw(TextAddEdge);
		for (auto i : connections) {
			MainWindow.draw(&i.linest[0], i.linest.size(), Lines);
			MainWindow.draw(i.name);
		}
		for (auto i : bestconnections) {
			MainWindow.draw(&i.linest[0], i.linest.size(), Lines);
		}
		for (auto i : cities) {
			MainWindow.draw(i.circle);
			MainWindow.draw(i.nodename);
		}
        MainWindow.display();
    }
    return 0;
}




