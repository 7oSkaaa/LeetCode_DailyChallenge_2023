//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{

    /*
        - To maximize our capital value, we need to choose projects that have a high profit value..
          But,We have a restriction in choosing projects. we can only choose the ones whose capital value less or equal to our base capital value 'w'

        - In otherwords, We need to guarantee that our capital value will allow us to choose between various projects
        - First we sort the projects increasingly with respect to their capital value
          if our base capital is bigger than or equal  to current project's capital then we store project's profit in a max heap "priority queue"
          otherwise we need to make the base capital as max as possible to take current project by taking stored profits from the max heap,
          then we store project's profit in max heap and so on..
        - Keep in mind taking stored profits from max heap means we officially take these projects so we do it with respect to 'k'
        - Why Don't we take all projects in case our capital is high enough?
          because we may miss taking projects's that have a higher profits, so we limit ourselves by taking high profit projects only in the need of widen
          our possible projects to be taken.
    */
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> v(sz(profits)); // to store our projects [capital,profits]

        priority_queue<int> pq; // our max heap to store the proposed projects' profits that might be offically taken

        for (int i = 0; i < sz(profits); i++)
            v[i] = {capital[i], profits[i]};

        sort(v.begin(), v.end()); // sort projects increasingly with respect to their capital values

        for (int i = 0; i < sz(v) && k; i++)
        {
            /*
            if current project's capital is bigger than our base capital
            then we take from our maxheap the maximum needed profits to make capital bigger.
            that all with respect to our limit is at most k projects..
            */
            while (w < v[i].first && sz(pq) && k--)
                w += pq.top(), pq.pop();

            if (w >= v[i].first) // our capital is bigger or equal to project's capital then we store it in our max heap "as their maybe exists further or previous projects we can benefit from their profit which are higher than current one"
                pq.push(v[i].second);
        }

        while (sz(pq) && k--) // we did not choose all k projects? then our capital is high enough for all max heap's elements,so we take them till finishing k
            w += pq.top(), pq.pop();

        return w;
    }
};
