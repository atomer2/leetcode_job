// Since our timestamps are only increasing, we can use a vector instead of a map, though it's not as concise.
class SnapshotArray{
    unordered_map<int, vector<pair<int, int>>> m;
    int cur_snap = 0;
    int snap() { return cur_snap++; }
    void set(int index, int val) {
        if (m[index].empty() || m[index].back().first != cur_snap)
            m[index].push_back({ cur_snap, val });
        else m[index].back().second = val;
    }
    int get(int index, int snap_id) {
        auto it = upper_bound(begin(m[index]), end(m[index]), pair<int, int>(snap_id, INT_MAX));
        return it == begin(m[index]) ? 0 : prev(it)->second;
    }
};
