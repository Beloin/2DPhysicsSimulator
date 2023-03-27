# 2D Video Game physics

## 2D physics for particle

Base equations for movement:  
dt = t(i+1) - ti  
v(ti+1) = v(ti)  + (f(ti)/m)dt  
p(ti+1) = p(ti) + v(ti+1)dt

## 2D Physics for Rigid Body

### Position and Mass properties

Center of Mass:
$\frac{m_i*r_i}{M}$

If the density of the figure is uniform,
then the center of mass is the same as the
geometric center also known as centroid.

Since rigid body are continues through the particles, we should not
use a discrete equation, but use an integral to calculate the Center of mass
of a Rigid Body:  
$\frac{1}{M} \int_v p(r)r\, dv$

Where r is the position of each point ,p is a function that gives the density
at each point within the body (there's the [v]olume part).

### Angular Properties

Since we only have to worry about one dimension of rotation
(the one which points out to the screen), to simplify the calculations
we will be using 0->$\pi$


## Collisions

For sake of simplicity, we will not be using any advanced methods, like SAT or DBVT.

The method we are using is the `Axis Aligned Bounding Boxes` that can be calculated using `AABBvsAABB` function.

We simply check if one Axis-Aligned box is inside another Axis-Aligned Box:

<img src="/resources/AABB.png" alt="AABB showcase"/>
