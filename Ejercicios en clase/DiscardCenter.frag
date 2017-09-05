#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

void main()
{
	FragColor = vec4(InterpolatedColor, 1.0f);
	vec2 pixelPositionInWindow =gl_FragCoord.xy;

	vec2 Center = vec2 (200.0f,200.0f);

	vec2 Result = Center - pixelPositionInWindow;

	if(sqrt((Result.x)*(Result.x)+(Result.y)*(Result.y)) <100.00f){
		discard;
	}
}