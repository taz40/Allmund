#shader vertex
#version 330 core
layout(location = 0) in vec4 position;

uniform mat4 u_MV;
uniform mat4 u_Projection;
out float dist;

void main() { 
	vec4 newPos = u_MV * position;
	dist = -newPos.z;
	gl_Position = u_Projection * newPos;
}

#shader fragment
#version 330 core
layout(location = 0) out vec4 color; 
uniform vec4 u_Color;

in float dist;

void main() { 
	color = 2.5f/dist * u_Color; 
}