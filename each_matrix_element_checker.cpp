int dx[8] = {-1,-1,-1,0,0,1,1,1};
  int dy[8] = {-1,0,1,-1,1,-1,0,1};

  
  std::vector<vector<char>> vv(n, std::vector<char>(m));
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
          std::cin >> a[i][j];
      }
  }
  
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
  
          for (int d = 0; d < 4; d++) {
              int ni = i + dx[d];
              int nj = j + dy[d];
  
              if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                  // SAFE access
                  // a[ni][nj]
              }
          }
      }
  }
