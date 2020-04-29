// Fade out per frame
image_alpha -= 0.01;

// Destroy once transparent
if (image_alpha <= 0)
{
	instance_destroy();
}
