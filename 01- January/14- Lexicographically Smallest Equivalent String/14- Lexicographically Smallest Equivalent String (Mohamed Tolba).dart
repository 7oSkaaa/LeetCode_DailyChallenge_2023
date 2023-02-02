// Author: Mohamed Tolba

class UnionFind {
  List<int> parent = List.filled(26, 0);

  // find the parent

  int find(int a) {
    if (a != parent[a]) {
      parent[a] = find(parent[a]);
    }
    return parent[a];
  }

  void union(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    // make smaller one represent of other if parent is different

    if (parentA < parentB) {
      parent[parentB] = parentA;
    } else {
      parent[parentA] = parentB;
    }
  }

  UnionFind() {
    for (int i = 0; i < 26; ++i) {
      parent[i] = i;
    }
  }
}

class Solution {
  String smallestEquivalentString(String s1, String s2, String baseStr) {
    // make group union

    UnionFind uf = UnionFind();
    for (int i = 0; i < s1.length; ++i) {
      uf.union(
          s1.codeUnitAt(i) - 'a'.codeUnitAt(0), s2.codeUnitAt(i) - 'a'.codeUnitAt(0));
    }

    // traverse in the baseStr and find the parent of ech char

    StringBuffer sb = StringBuffer();
    for (String ch in baseStr.split("")) {
      sb.writeCharCode(
          ('a'.codeUnitAt(0) + uf.find(ch.codeUnitAt(0) - 'a'.codeUnitAt(0))));
    }
    return sb.toString();
  }
}