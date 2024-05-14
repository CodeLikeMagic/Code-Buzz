class Node:
    def __init__(self, page):
        self.page = page
        self.prev = None
        self.next = None

class BrowserHistory:

    def __init__(self, homepage: str):
        self.homePg = Node(homepage)
        self.current = self.homePg
        
    def visit(self, url: str) -> None:
        newPage = Node(url)
        self.current.next = newPage
        newPage.prev = self.current
        self.current = newPage

    def back(self, steps: int) -> str:
        while steps:
            if self.current.prev:
                self.current = self.current.prev
                steps = steps - 1
            else:
                break
        return self.current.page

    def forward(self, steps: int) -> str:
        while steps:
            if self.current.next:
                self.current = self.current.next
                steps = steps - 1
            else:
                break
        return self.current.page


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)