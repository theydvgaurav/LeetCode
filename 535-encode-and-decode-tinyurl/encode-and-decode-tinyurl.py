from uuid import uuid4
class Codec:

    d = {}

    def encode(self, longUrl: str) -> str:
        """
            Encodes a URL to a shortened URL.
        """
        code = str(uuid4())
        self.d[code]  = longUrl
        return code

        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        long_url = self.d.get(shortUrl,"")
        self.d.pop(shortUrl,None)
        return long_url
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))