/*一个迷宫由n行m列的单元格组成，(n，m均小于50)，每个单元格要么是空地，要么是障碍物，请找到一条从起点到终点的最短路径长度。*/
void dfs(int x, int y, int step)//深度优先搜索 
{	
	//x,y表示当前位置，step表示已走步数
	//判断是否到达终点
	if(x == endx && y = endy)
	{
		step = step < min?step : min;		//更新最短步数
		return;							//已经到达终点，结束dfs函数
	}

	/	/未到达终点时，按右下左上的顺序进行依次遍历
	//对右侧
	if (map[x][y+1] == 1 && v[x][y+1] == 0)
	{	
		//map[x][y+1]==1表示右边无障碍，v[x][y+1]==0表示右边方格未经过
		//则现在可进入右边方格
		v[x][y+1] = 1;	//标记右边方格，表示已经过
		dfs(x, y+1, step+1);	//递归调用，在右侧单元格进行下一次的dfs
		
		//进行到这里时，表示递归已经结束，进行回溯，即从右侧返回
		v[x][y+1] = 0;
	}
		//对剩下三侧，类比右侧代码即可
	if(map[x+1][y] == 1 && v[x+1][y] == 0)
	{	
		//下
		v[x+1][y] = 1;
		dfs(x+1, y, step+1);
		v[x+1][y] = 0;
	}
	if(map[x][y-1] == 1 && v[x][y-1] == 0)
	{	
		//左
		v[x][y-1] = 1;
		dfs(x, y-1, step+1);
		v[x][y-1] = 0;
	}
	if(map[x-1][y] == 1 && v[x-1][y] == 0)
	{	
		//上
		v[x-1][y] = 1;
		dfs(x-1, y, step+1);
		v[x-1][y] = 0;
	}
	
	return;
}

