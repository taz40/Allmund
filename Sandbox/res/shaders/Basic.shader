#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec3 aNormal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
out float dist;
out vec3 Normal;
out vec3 fragPos;

void main() { 
	Normal = mat3(transpose(inverse(u_Model))) * aNormal;
	vec4 newPos = u_View * u_Model * position;
	dist = -newPos.z;
	fragPos = vec3(u_Model * position);
	gl_Position = u_Projection * newPos;
}

#shader fragment
#version 330 core
layout(location = 0) out vec4 color; 
uniform vec3 u_Color;
uniform vec3 u_LightPos;
uniform vec3 u_ViewPos;

in float dist;
in vec3 Normal;
in vec3 fragPos;

void main() {
	vec3 lightColor = vec3(1.0, 1.0, 1.0);

	//difuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(u_LightPos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	//specular
	float specularStrength = 0.5;
	vec3 viewDir = normalize(u_ViewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = specularStrength * spec * lightColor;


	// ambient
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;

	//final
	vec3 result = (diffuse + ambient + specular) * u_Color;
	//result = ambient;
	color = vec4(result, 1.0); 
}