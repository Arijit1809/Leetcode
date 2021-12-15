class Solution(object):
    """  """
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        from collections import defaultdict
        self.flightMap = defaultdict(list)

        for ticket in tickets:
            origin, dest = ticket[0], ticket[1]
            self.flightMap[origin].append(dest)

        self.visitBitmap = {}

        # sort the itinerary based on the lexical order
        for origin, itinerary in self.flightMap.items():
        # Note that we could have multiple identical flights, i.e. same origin and destination.
            itinerary.sort()
            self.visitBitmap[origin] = [False]*len(itinerary)

        self.flights = len(tickets)
        self.result = []
        route = ['JFK']
        self.backtracking('JFK', route)

        return self.result


    def backtracking(self, origin, route):
        if len(route) == self.flights + 1:
            self.result = route
            return True

        for i, nextDest in enumerate(self.flightMap[origin]):
            if not self.visitBitmap[origin][i]:
                # mark the visit before the next recursion
                self.visitBitmap[origin][i] = True
                ret = self.backtracking(nextDest, route + [nextDest])
                self.visitBitmap[origin][i] = False
                if ret:
                    return True

        return False