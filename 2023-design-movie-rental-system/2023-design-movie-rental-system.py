import bisect
from collections import defaultdict

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.movie_map = defaultdict(list)  # movie -> list of (price, shop)
        self.rented_list = []               # sorted list of (price, shop, movie) for rented movies
        self.shop_movie_price = {}           # key: (shop, movie) -> price
        self.rented_set = set()              # set of (shop, movie) for quick lookup
        
        for entry in entries:
            shop, movie, price = entry
            self.movie_map[movie].append((price, shop))
            self.shop_movie_price[(shop, movie)] = price
        
        for movie in self.movie_map:
            self.movie_map[movie].sort(key=lambda x: (x[0], x[1]))

    def search(self, movie: int) -> List[int]:
        if movie not in self.movie_map:
            return []
        lst = self.movie_map[movie]
        res = []
        count = 0
        for price, shop in lst:
            if (shop, movie) not in self.rented_set:
                res.append(shop)
                count += 1
                if count == 5:
                    break
        return res

    def rent(self, shop: int, movie: int) -> None:
        price = self.shop_movie_price[(shop, movie)]
        # Remove from movie_map
        lst = self.movie_map[movie]
        left, right = 0, len(lst) - 1
        idx = -1
        while left <= right:
            mid = (left + right) // 2
            p, s = lst[mid]
            if p == price and s == shop:
                idx = mid
                break
            elif p < price or (p == price and s < shop):
                left = mid + 1
            else:
                right = mid - 1
        if idx != -1:
            del lst[idx]
        self.rented_set.add((shop, movie))
        # Insert into rented_list in sorted order
        bisect.insort(self.rented_list, (price, shop, movie), key=lambda x: (x[0], x[1], x[2]))

    def drop(self, shop: int, movie: int) -> None:
        price = self.shop_movie_price[(shop, movie)]
        # Add back to movie_map
        lst = self.movie_map[movie]
        bisect.insort(lst, (price, shop), key=lambda x: (x[0], x[1]))
        self.rented_set.remove((shop, movie))
        # Remove from rented_list
        left, right = 0, len(self.rented_list) - 1
        idx = -1
        while left <= right:
            mid = (left + right) // 2
            p, s, m = self.rented_list[mid]
            if p == price and s == shop and m == movie:
                idx = mid
                break
            elif (p < price) or (p == price and s < shop) or (p == price and s == shop and m < movie):
                left = mid + 1
            else:
                right = mid - 1
        if idx != -1:
            del self.rented_list[idx]

    def report(self) -> List[List[int]]:
        res = []
        for i in range(min(5, len(self.rented_list))):
            price, shop, movie = self.rented_list[i]
            res.append([shop, movie])
        return res