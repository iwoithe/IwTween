#pragma once

#include <cmath>

namespace iw
{
	template<typename T>
	class Tween
	{
	public:
		Tween()
		{
			/* Default constructor, remember to run `Tween::setStart` and
			   `Tween::setEnd` before calling `Tween::at` or
			   `Tween::getCurrentValue` */
			m_alpha = 0.0f;
		}

		Tween(T start, T end)
		{
			Tween(start, end, 0.0f);
		}

		Tween(T start, T end, float alpha)
		{
			m_start = start;
			m_end = end;
			m_alpha = alpha;
		}

		typedef T(*InterpFunc)(T, T, float);

		T getCurrentValue()
		{
			/* Return the current value of this tween using linear
			   interpolation (the default interpolation) */
			return at(m_alpha);
		}

		T getCurrentValue(Tween<T>::InterpFunc interpFunc = linearInterp)
		{
			// Return the current value of this tween
			return at(m_alpha, interpFunc);
		}

		T at(float alpha, Tween<T>::InterpFunc interpFunc = linearInterp)
		{
			/* Return the value of this tween at the specified alpha.
			   Allows using a custom variable as alpha to get the value
			   of a tween
			
			   For example,

			   while (true) {
			       // Calculate delta time here

			       elapsedTime += deltaTime;

			       std::cout << tween.at(std::cos(elapsedTime)) << std::endl;
			   } */
			return interpFunc(m_start, m_end, alpha);
		}

		T getStart() const
		{
			// Return the start value
			return m_start;
		}

		void setStart(T start)
		{
			// Set the start value
			m_start = start;
		}

		T getEnd() const
		{
			// Return the end value
			return m_end;
		}

		void setEnd(T end)
		{
			// Set the end value
			m_end = end;
		}

		float getAlpha() const
		{
			// Return this tween's alpha value
			return m_alpha;
		}
		
		void setAlpha(float alpha)
		{
			// Set this tween's alpha value
			m_alpha = alpha;
		}
		
		void addAlpha(float amount)
		{
			// Add a value to this tween's alpha value
			m_alpha += amount;
		}
		
		void subAlpha(float amount)
		{
			// Subtract a value from this tween's alpha value
			m_alpha -= amount;
		}

		// Interpolation functions

		static T linearInterp(T start, T end, float alpha)
		{
			return (end - start) * alpha + start;
		}

		static T easeInCubicInterp(T start, T end, float alpha)
		{
			return (end - start) * alpha * alpha * alpha + start;
		}

		static T easeInOutExpoInterp(T start, T end, float alpha)
		{
			float a = alpha == 0 ? 0 : alpha == 1 ? 1 : alpha < 0.5 ? std::pow(2, 20 * alpha - 10) / 2 : (2 - std::pow(2, -20 * alpha + 10)) / 2;
			return (end - start) * a + start;
		}

		static T easeOutQuartInterp(T start, T end, float alpha)
		{
			float a = 1 - std::pow(1 - alpha, 4);
			return (end - start) * a + start;
		}

	private:
		T m_start;
		T m_end;
		float m_alpha;
	};
}
