"""
    MORAI Module
    ~~~~~~~~~~~~~

"""
#from lib.common.logger import Logger
#import numpy as np

class Math(object):
    """A class that can perform various operations using numpy, a vector and matrix operation library.
    
    """


    def __init__(self, a, b):
        self._a = a
        self._b = b


    def arclength_of_line(self, x, y):
        """A function that returns the length of the entire curve surrounded by the parameters x and y at y=f(x).
        
        :param int x: x-axis length
        :param int y: y-axis length
        :returns arc: entire curve length
        
        **Descriptions**: Divide the lengths of the x-axis and y-axis by 'num_segments', and calculate the straight length surrounded by the x-axis and y-axis division section using the Pythagorean hypotenuse length formula.
          Add up each straight length calculated as many times as 'num_segments', the number of division section on the x-axis and y-axis (the number of intervals on the x-axis and y-axis is the same).
          At this time, the larger the 'num_segments', the smaller the division interval, so the straight length close to the curve is obtained.

        **Example**:
            When the x-axis division section for a specific index is 'x[indx] - x[indx - 1]', the length of the entire curve surrounded by the x-axis and y-axis division section can be calculated as follows.

            >>> for indx in range(1, num_segments):
                    arc = arc + np.sqrt((x[indx] - x[indx - 1])**2 + (y[indx] - y[indx - 1])**2)
        """
        if len(x) != len(y):
            Logger.log_error('Check dimensions of the line')
            return
 
        num_segments = len(x)
        arc = 0
        
        for indx in range(1, num_segments):
            arc = arc + np.sqrt((x[indx] - x[indx - 1])**2 + (y[indx] - y[indx - 1])**2)
        
        return arc


    def coordinate_transform_point(self, angle, point):
        """A function that returns a new coordinate P' when the coordinate P rotates three times in 2D coordinate system with rotation axes X and Y.

        :param int angle: a rotation angle about the origin
        :param tuple point: a reference coordinate P. Represented by a 2-element vector p=(px,py).
        :returns transform_pt: a new coordinate P'

        **Descriptions**: Calculate a new coordinate rotated three times using the inner product of the rotation matrix.
            The rotation matrix can be calculated as follows:

            >>> rotation = np.array(((np.cos(angle), -np.sin(angle)),
            (np.sin(angle), np.cos(angle))))
            
        """
        rotation = np.array(((np.cos(angle), -np.sin(angle)),
            (np.sin(angle), np.cos(angle))))
 
        transform_pt = rotation.dot(point[0:2])
        
        return transform_pt

