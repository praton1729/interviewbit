
class Interval:

    def __init__(self,s=0,e=0):

        self.start = s

        self.end = e

def merge(intervals):

	sorted_by_lower_bound = sorted(intervals, key = lambda tup:tup.start)
	merged = []
        
        for tup in sorted_by_lower_bound:
            
            if not merged:
            
                merged.append(tup)
            
            else:
                
                b = merged.pop()
                
                if b.end >= tup.start :
                    
                    new_tup = Interval(b.start,max(b.end, tup.end))
                    
                    merged.append(new_tup)
                else:
                    merged.append(b)
                    merged.append(tup)
                    
        return merged
                
                
                 

intervals = [Interval(1,2),Interval(3,4),Interval(1,3)]

print merge(intervals)[0].end

    
